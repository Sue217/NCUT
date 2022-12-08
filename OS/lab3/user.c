#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "fs.h"
#include "user.h"

int f_create(char* file_name, char* mode, char* type) {
  // find an empty inode
  int ei = find_empty_inode();
  assert(~ei);

  // find an empty block
  int eb = find_empty_block();
  assert(~eb);

  // claim them
  inodes[ei].first_block = eb;
  dbs[eb].next_block = LAST;

  // connect file with inode
  int fd = ei;
  files[fd].ip = &inodes[fd];
  strcpy(files[fd].name, file_name);

  short md = (short) (mode[0] - '0');
  short tp = (short) (type[0] - '0');

  // complete file attributes
  switch (md) {
    /*
     * read: 4
     * write: 2
     * execute: 1
     */
    case 0:
      files[fd].readable = files[fd].writable = files[fd].executable = 0;
      break;
    case 1:
      files[fd].executable = 1;
      files[fd].readable = files[fd].writable = 0;
      break;
    case 2:
      files[fd].writable = 1;
      files[fd].readable = files[fd].executable = 0;
      break;
    case 3:
      files[fd].writable = files[fd].executable = 1;
      files[fd].readable = 0;
      break;
    case 4:
      files[fd].readable = 1;
      files[fd].writable = files[fd].executable = 0;
      break;
    case 5:
      files[fd].readable = files[fd].executable = 1;
      files[fd].writable = 0;
      break;
    case 6:
      files[fd].readable = files[fd].writable = 1;
      files[fd].executable = 0;
      break;
    case 7:
      files[fd].readable = files[fd].writable = files[fd].executable = 1;
      break;
    default:
      break;
  }

  files[fd].type = tp;
//  printf("type = %d\n", tp);

  // return the file descriptor
  return fd;
}

int f_delete(char* file_name) {
  struct file* fp = files;
  for (int i = 0; i < sb.ninodes; i++, fp++) {
    if (fp->ip == NULL) continue;
    if (strcmp(file_name, fp->name) == 0) {
      memset(fp->name, 0, sizeof(fp->name));
      fs_free(fp->ip->first_block);
      return SUCCESS;
    }
  }
  return FAILED;
}

int f_open(int fd) {
  if (files[fd].type == FOLDERS) {
    printf("Not a file ");
    return FAILED;
  }
  return SUCCESS;
}

int f_close(int fd) {
  if (files[fd].type == FOLDERS) {
//    puts("Not a file");
    return FAILED;
  }
  return SUCCESS;
}

char* f_read(char* file_name) {
  struct file* fp = files;
  for (int i = 0; i < sb.ninodes; i++, fp++) {
    if (strcmp(fp->name, file_name) == 0) {
      int fd = fp->ip->inum;
      if (fp->readable == 0 || f_open(fd) == FAILED) {
        return NULL;
      }
      fs_sync();
      int bid = fp->ip->first_block;
      int nn = 0;
      static char con[BLOCK_SIZE << 2] = {0};
      while (bid != LAST) {
        char tmp[BLOCK_SIZE] = {0};
        strcpy(tmp, dbs[bid].data);
//        printf("%lu\n%s\n", strlen(tmp), dbs[bid].data);
        // copy data from disk block
        char* cc = tmp;
        while (*cc) {
          con[nn++] = *cc;
          cc++;
        }
        bid = dbs[bid].next_block;
      }
      f_close(fd);
      return con;
    }
  }
  return NULL;
}

int f_write(char* file_name, char* content) {
  struct file* fp = files;
  for (int i = 0; i < sb.ninodes; i++, fp++) {
    if (strcmp(fp->name, file_name) == 0) {
      // write here
      int fd = fp->ip->inum;
      if (fp->writable == 0 || f_open(fd) == FAILED) {
        return FAILED;
      }

      // update file size
      int len = (int) strlen(content);
      fp->ip->size += len;

      // alloc first
      int bid = fs_alloc(fd, len);

//      write_byte(fd, 0, content);
      strcpy(dbs[bid].data, content);

      f_close(fd);
      return SUCCESS;
    }
  }
  return FAILED;
}

void f_dir() {
  struct file* fp = files;
  for (int i = 0; i < sb.ninodes && fp->ip; i++, fp++) {
    char prod[5] = "----";
    if (fp->type == FOLDERS) {
      prod[0] = 'd';
    }
    if (fp->readable == 1) {
      prod[1] = 'r';
    }
    if (fp->writable == 1) {
      prod[2] = 'w';
    }
    if (fp->executable == 1) {
      prod[3] = 'x';
    }
    printf("%s    %p    %d    %s\n", prod, fp->ip, fp->ip->size, fp->name);
  }
}