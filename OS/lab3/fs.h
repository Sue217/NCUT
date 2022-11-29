// On-disk file system format.
// Meta information (meta-data) about fs.
// Both the kernel and user programs use this header file.

#ifndef __FILE_SYSTEM_H__
#define __FILE_SYSTEM_H__

#define BLOCK_SIZE 512  // size of block
#define NAME_SIZE 16    // max name length

#define FILES 0
#define FOLDERS 1

enum status { INIT = -1, LAST = -2 };

struct superblock {
  int size;     // size of disk blocks
  int nblocks;  // number of disk blocks
  int ninodes;  // number of inodes
};  // 12 bytes

struct inode {
  int size;
  int inum;               // inode number (index of inodes array)
  int first_block;        // first block of inode
};  // 12 bytes

struct diskblock {
  int next_block;         // next block number
  char data[BLOCK_SIZE];  // block content
};  // 516 bytes

struct file {
  short type;             // folder or just file
  short readable;
  short writable;
  short executable;
  struct inode* ip;       // index of inode
  char name[NAME_SIZE];   // file name
};  // 32 bytes

struct superblock sb;
struct inode* inodes;
struct diskblock* dbs;
struct file* files;

void fs_create();  // create new fs
void fs_sync();    // write the fs

int find_empty_inode();
int find_empty_block();

int fs_init(char filename[NAME_SIZE], short mode, short type); // allocate the file return file number

int grow(int total, int bid);
void shrink(int bid);

int fs_alloc(int id, int size);     // set file size
void fs_free(int id);     // set file size

int get_block_number(int fnum, int block);

void write_byte(int fnum, int pos, char* xs);

void print();

#endif  // __FILE_SYSTEM_H__