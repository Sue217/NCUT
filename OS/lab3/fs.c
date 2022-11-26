#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fs.h"

void fs_create() {
  sb = (struct superblock) {
    .size = sizeof(struct diskblock),
    .ninodes = 10,
    .nblocks = 100,
  };
  inodes = malloc(sizeof(struct inode) * sb.ninodes);
  dbs = malloc(sizeof(struct diskblock) * sb.nblocks);

  struct inode* ip = inodes;
  for (int i = 0; i < sb.ninodes; i++, ip++) {
    ip->size = 1;
    ip->first = INIT;
    strcpy(ip->name, "init");
  }

  struct diskblock* dp = dbs;
  for (int i = 0; i < sb.nblocks; i++, dp++) {
    dp->next = INIT;
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
  FILE* file = fopen("data", "w+");
  fwrite(&sb, sizeof(struct superblock), 1, file);
  fwrite(inodes, sizeof(struct inode), sb.ninodes, file);
  fwrite(dbs, sizeof(struct diskblock), sb.nblocks, file);
  fclose(file);
}

int falloc(char filename[NAME_SIZE]) {
  // find an empty inode
  int ei = find_empty_inode();
  // find an empty block
  int eb = find_empty_block();
  // claim them
  inodes[ei].first = eb;
  dbs[eb].next = LAST;
  // return the file descriptor
  return ei;
}

void fsset(int id, int size) {
  // how many blocks we should have
  int total = (size + BLOCK_SIZE - 1) / BLOCK_SIZE - 1;
  int bid = inodes[id].first;

  // extend the file if necessary...
  bid = grow(total, bid);

  // contract the file...
  bid = shrink(bid);
  dbs[bid].next = LAST;
}

void write_byte(int fnum, int pos, char* xs) {
  // calculate which block is
  int block = pos / BLOCK_SIZE;

  // find the block number
  int bnum = get_block_number(fnum, block);

  // calculate the offset
  int offset = pos % BLOCK_SIZE;

  // write the data
  dbs[bnum].data[offset] = *xs;
}
