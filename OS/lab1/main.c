/*
 *  author: Jingbo Su
 *  created: Thu Sep 29 2022
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "process.h"
#include "fcfs.h"
#include "rr.h"
#include "pp.h"

int main(int argc, char *argv[]) {
  srand(time(NULL));
  if (argc == 2) {
    char* strategy = argv[1];
    initialize();
    if (strlen(strategy) == 4) {
      // First Come First Serve
      fcfs_run();
    } else
    if (strategy[0] == 'r' && strategy[1] == 'r') {
      // Round Robin
      rr_run();
    } else
    if (strategy[0] == 'p' && strategy[1] == 'p') {
      // Preemptive Priority
      pp_run();
    } else {
      puts("Invalid input operation");
      exit(0);
    }
  } else
  if (argc == 1) {
    initialize();
    puts("FCFS Running...");
    fcfs_run(); refresh();
    puts("Round Robin Running...");
    rr_run(); refresh();
    puts("Preemptive Priority Running...");
    pp_run(); refresh();
  } else {
    puts("Invalid input operation");
    exit(0);
  }
  return 0;
}
