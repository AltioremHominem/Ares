#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>

#include "rendering.h"
#include "fileIO.h"

#define VERSION_INFO " "

#define HELP_INFO " "

#define ERROR_INFO " "

static struct option long_options[] = {
  {"help",no_argument, 0, 'h'},
  {"version",no_argument, 0, 'h'},
  {0,0,0,0}
  
};

int main(int argc, char  **argv){
  short opt;
  short opt_index = 0;
  if (argc == 0) {
    startCurses(NULL); //rendering.c Function   

  } else {
    if (optind < argc) {
      filename = argv[optind];
    }
      while ((opt = getopt_long(argc, argv, "hv",long_options, &opt_index)) != -1) {
        switch(opt){
          case 'h':
            printf(HELP_INFO);
              return 0;
            break;
          case 'v':
            printf(VERSION_INFO);
          return 0;
            break;
          case '?':
            for(i=0;filename[i] != '\0' ; i++) {
              
                if(filename[] == '*' || filename[] == '?' || filename[] == '/' || filename[] == '\\' ){
                  printf(ERROR_INFO);
                  return 1;
                } else {
                                          startCurses(filename); //rendering.c Function but calling an IO
            }
           }
            break;
          default:
            break:
        
      }
    } 
  }



  return 0;
}
