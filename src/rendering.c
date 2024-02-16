#include <stdlib.h>
#include <stdio.h>

#include <termbox.h>

#include "fileIO.h"
#include "rendering.h"
#include "modes.h"


#define ERROR_MESSAGE "NOT ENOUGH ESPACE"

#define NORMAL_MODE 0
#define INSERT_MODE 1
#define COMMAND_MODE 2

char *archiveText; // ? Is Used to manage the file input

// ! WIP
void screenRendering(char *filename){ // ? Print the "~" in all the first X position except when there is text
    int width, height;
    width = tb_width();
    height = tb_height();
    uint16_t bg = TB_BLACK;
    uint16_t fg = TB_WHITE; 
    for (short i = 0; i <= width; i++)
    {
        tb_change_cell(i,1,' ',fg,TB_WHITE);
        tb_present();
    }
    if (filename == NULL) {


    } else {

    }
}



void textRendering(char *archiveText){ // ? Rendering of the text of the input file
    short y = 0, x = 0;
    uint16_t bg = TB_BLACK;
    uint16_t fg = TB_WHITE;
    // ? Loop through each character in the array and print it on the screen
    for (int i = 0; archiveText[i] != '\0'; i++){
        if (archiveText[i] == '\n') {
            x = 0;
            y++;
        }
        tb_change_cell(x,y,archiveText[i],fg,bg);
        x++;
        tb_present();
    }
}

void startRenderTermBox(char *filename){
    tb_init();
    tb_clear();
    tb_present(); // ? Init TermBox Functions
    int width, height;
    width = tb_width();
    height = tb_height();
    tb_select_input_mode(TB_INPUT_ESC);
    if ( width < 80 || height < 24) {
        printf(ERROR_MESSAGE);
        exit(1);
    }

    if (filename == NULL) { // ? If there is no archive, start rendering, if is there is archive, process archive
    screenRendering(filename);
    normalMode();
    
    } else {
    screenRendering(filename);
    fileInput(filename);
    archiveText=(char *)malloc(1 * sizeof(*archiveText));
    textRendering(archiveText);
    free(archiveText);
    normalMode();
    }

}