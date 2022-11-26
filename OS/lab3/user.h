// system calls

#define MAX_LEN 256

void file_create(char* file_name) {
  char cmd[MAX_LEN];
  snprintf(cmd, sizeof cmd, "touch %s", file_name);
  system(cmd);
}

void file_delete(char* file_name) {
  char cmd[MAX_LEN];
  snprintf(cmd, sizeof cmd, "rm -rf %s", file_name);
  system(cmd);
}

void file_open(char* file_name) {
  char cmd[MAX_LEN];
  snprintf(cmd, sizeof cmd, "open %s", file_name);
  system(cmd);
}