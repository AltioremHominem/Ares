#include <stdlib.h>
#include <stdio.h>

#include <termbox.h>

#include "fileIO.h"
#include "rendering.h"

#define ESCAPE 27
#define SPACE 32
#define ENTER 10
#define DOWN_ARROW 258
#define UP_ARROW 259
#define LEFT_ARROW 260
#define RIGHT_ARROW 261

#define STARTING_ROWS_SIZE 128
#define STARTING_ROW_SIZE 64

#define ERROR_MESSAGE "NOT ENOUGH ESPACE"

char *archiveText; // ? Is Used to manage the file input


void screenRendering(){
    struct tb_cell *cells = tb_cell_buffer(); // ? This is used to make the terminal output match the terminal color scheme.
    uint16_t bg = cells[5 + 5 * tb_width()].bg;
}

void inputRendering(){
    while (1) {

    }

}

void textRendering(char *archiveText){ // ? Rendering of the text of the input file
    for (long unsigned i = 0; i < sizeof(archiveText);i++){



    }


}

void startRenderTermBox(char *filename){
    tb_init();
    tb_present(); // ? Init TermBox Functions
    int width, height;
    width = tb_width();
    height = tb_height();
    tb_select_input_mode(TB_INPUT_ESC);
    if ( width < 80 || height < 24) {
        printf(ERROR_MESSAGE);
        exit(1);
    }

    if (filename == NULL) {
    screenRendering();
    
    } else {
        screenRendering();
    fileInput(filename);
    archiveText=(char *)malloc(1 * sizeof(archiveText));
    textRendering(archiveText);
    free(archiveText);
    }

}


void finishRenderTermBox(){
    tb_shutdown();   // ? End TermBox End Function
}
