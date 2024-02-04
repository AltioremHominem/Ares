#include <stdbool.h>
#include <stdlib.h>

#include <curses.h>

#include "fileIO.h"

#define ESCAPE 27
#define SPACE 32
#define ENTER 10
#define DOWN_ARROW 258
#define UP_ARROW 259
#define LEFT_ARROW 260
#define RIGHT_ARROW 261

#define STARTING_ROWS_SIZE 128
#define STARTING_ROW_SIZE 64



void screenRendering(){



  
}

void startCurses(char *filename){
  initscr(); //Ncurses Functions
  cbreak();
  noecho();
  raw();
  keypad(stdscr,TRUE);

  init_colors();


  if (filename == NULL) {

    
  } else {
    char *archiveText;
    archivetext=(char *)malloc(1 * sizeof(fileInput(filename));
    free(archiveText);
  }

  

  
}


void finishCurses(){
  endwin(); //NCurses End Function

  
}
