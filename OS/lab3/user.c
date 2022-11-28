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
  printf("type = %d\n", tp);

  // return the file descriptor
  return fd;
}

int f_delete(char* file_name) {
  struct file* fp = files;
  for (int i = 0; i < sb.ninodes; i++, fp++) {
    if (strcmp(file_name, fp->name) == 0) {
      fs_free(fp->ip->first_block);
      return SUCCESS;
    }
  }
  return FAILED;
}

int f_open(char* file_name) {
  // I don't know what to do...
  return 0;
}

int f_close(char* file_name) {
  // I don't know what to do...
  return 0;
}

char* f_read(char* file_name) {
  struct file* fp = files;
  for (int i = 0; i < sb.ninodes; i++, fp++) {
    if (strcmp(fp->name, file_name) == 0) {
      if (fp->readable == 0) {
        return NULL;
      }
//      int fd = fp->ip->inum;
      fs_sync();
      int bid = fp->ip->first_block;
      int nn = 0;
      char con[BLOCK_SIZE] = {0};
      while (bid != LAST) {
        char tmp[BLOCK_SIZE] = {0};
        strcpy(tmp, dbs[bid].data);
        printf("%lu\n%s\n", strlen(tmp), tmp);
        // copy data from disk block
        char* cc = tmp;
        while (*cc) {
          con[nn++] = *cc;
          printf("%c", *cc);
        }
        puts("");
        bid = dbs[bid].next_block;
      }
      return con;
    }
  }
  return NULL;
}

int f_write(char* file_name, char* content) {
  struct file* fp = files;
  for (int i = 0; i < sb.ninodes; i++, fp++) {
    if (strcmp(fp->name, file_name) == 0) {
      if (fp->writable == 0) {
        return FAILED;
      }

      // update file size
      int len = (int) strlen(content);
      fp->ip->size += len;

      // write here
      int fd = fp->ip->inum;
      // alloc first
      fs_alloc(fd, len);

      write_byte(fd, 0, content);

      fs_sync();
      return SUCCESS;
    }
  }
  return FAILED;
}