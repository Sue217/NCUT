#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "fs.h"

void fs_create() {
  sb = (struct superblock) {
    .size = sizeof(struct diskblock),
    .ninodes = 16,
    .nblocks = 128,
  };
  inodes = malloc(sizeof(struct inode) * sb.ninodes);
  dbs = malloc(sizeof(struct diskblock) * sb.nblocks);
  files = malloc(sizeof(struct file) * sb.ninodes);

  struct inode* ip = inodes;
  for (int i = 0; i < sb.ninodes; i++, ip++) {
    ip->size = 1;
    ip->inum = i;
    ip->first_block = INIT;
  }

  struct diskblock* dp = dbs;
  for (int i = 0; i < sb.nblocks; i++, dp++) {
    dp->next_block = INIT;
    strcpy(dp->data, "");
  }
}

void fs_mount() {
  FILE* file = fopen("data", "r");
  fread(&sb, sizeof(struct superblock), 1, file);
  fread(inodes, sizeof(struct inode), sb.ninodes, file);
  fread(dbs, sizeof(struct diskblock), sb.nblocks, file);
  fclose(file);
}

void fs_sync() {
  FILE* fp = fopen("data", "w+");
  fwrite(&sb, sizeof(struct superblock), 1, fp);
  fwrite(inodes, sizeof(struct inode), sb.ninodes, fp);
  fwrite(dbs, sizeof(struct diskblock), sb.nblocks, fp);
  fwrite(files, sizeof(struct file), sb.ninodes, fp);
  fclose(fp);
}

int fs_init(char filename[NAME_SIZE], short mode, short type) {
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
  strcpy(files[fd].name, filename);

  // complete file attributes
  switch (mode) {
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

  files[fd].type = type;

  // return the file descriptor
  return fd;
}

void fs_alloc(int fd, int size) {
  // how many blocks we should have
  int total = (size + BLOCK_SIZE - 1) / BLOCK_SIZE - 1;
  int bid = inodes[fd].first_block;

  // extend the file if necessary...
  bid = grow(total, bid);
}

void fs_free(int fd) {
  int bid = inodes[fd].first_block;

  // contract the file if necessary...
  shrink(bid);
  dbs[bid].next_block = LAST;
}

// TODO: rewrite the write function!
void write_byte(int fnum, int pos, char* xs) {
  // calculate which block is
  int block = pos / BLOCK_SIZE;

  // find the block number
  int bnum = get_block_number(fnum, block);

  // calculate the offset
  int offset = pos % BLOCK_SIZE;

  // write the data
//  printf("[block] %d, [bnum] %d, [offset] %d\n", block, bnum, offset);
  int len = (int) strlen(xs);
  for (int i = 0, j = offset; i < len; i++, j++) {
    if (j >= BLOCK_SIZE) {
      j -= BLOCK_SIZE;
      bnum += 1;
    }
    dbs[bnum].data[j] = xs[i];
  }
//  dbs[bnum].data[offset] = *xs;
}
