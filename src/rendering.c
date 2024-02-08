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


void screenRendering(){ // ? Print the "~" in all the first X position except when there is text

}

void inputRendering(){ // ? Handles the input of the file
    struct tb_event event;
    tb_poll_event(&event);
    struct tb_cell *cells = tb_cell_buffer(); // ? This is used to make the terminal output match the terminal color scheme.
    uint16_t bg = cells[5 + 5 * tb_width()].bg;
    uint16_t fg = TB_WHITE;
    int current_mode = NORMAL_MODE;
    while (1) {
        if (event.type == TB_EVENT_KEY) {
            if (current_mode == NORMAL_MODE) {
                if (event.key == 'i') {
                    current_mode = INSERT_MODE;
                    tb_present();
                    insertMode();
                } else if (event.key == ':') {
                    current_mode = COMMAND_MODE;
                    tb_present();
                    commandMode();
                }
            } else if (current_mode == INSERT_MODE) {
                if (event.key == TB_KEY_ESC) {
                    current_mode = NORMAL_MODE;
                    tb_present();
                    normalMode();
                }
            } else if (current_mode == COMMAND_MODE) {
                if (event.key == TB_KEY_ESC) {
                    current_mode = NORMAL_MODE;
                    tb_present();
                    normalMode();
                }
            }
        }
    }
}

void textRendering(char *archiveText){ // ? Rendering of the text of the input file
    int y = 0, x = 0;
    struct tb_cell *cells = tb_cell_buffer(); // ? This is used to make the terminal output match the terminal color scheme.
    uint16_t bg = cells[5 + 5 * tb_width()].bg;
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
    inputRendering();
    
    } else {
        screenRendering();
    fileInput(filename);
    archiveText=(char *)malloc(1 * sizeof(archiveText));
    textRendering(archiveText);
    free(archiveText);
    inputRendering();
    }

}