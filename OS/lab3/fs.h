// On-disk file system format.
// Meta information (meta-data) about fs.
// Both the kernel and user programs use this header file.

#ifndef __FILE_SYSTEM_H__
#define __FILE_SYSTEM_H__

#define BLOCK_SIZE 512  // size of block
#define NAME_SIZE 16    // max name length

enum status { INIT = -1, LAST = -2 };

struct superblock {
  int size;     // size of disk blocks
  int nblocks;  // number of disk blocks
  int ninodes;  // number of inodes
};  // 12 bytes

struct inode {
  int size;     // what's its function?
  int first;
  char name[NAME_SIZE];
};  // 24 bytes

struct diskblock {
  int next;  // number of next block
  char data[BLOCK_SIZE];
};  // 516 bytes

struct superblock sb;
struct inode* inodes;
struct diskblock* dbs;

void fs_create();  // create new fs
void fs_mount();   // load the fs
void fs_sync();    // write the fs

int find_empty_inode();
int find_empty_block();

int falloc(char filename[NAME_SIZE]); // allocate the file return file number

int grow(int total, int bid);
int shrink(int bid);

void fsset(int id, int size);     // set file size

int get_block_number(int fnum, int block);

void write_byte(int fnum, int pos, char* xs);

void print();

#endif  // __FILE_SYSTEM_H__