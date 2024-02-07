#include <stdlib.h>
#include <stdio.h>

#include <termbox.h>

#include "fileIO.h"
#include "rendering.h"

#define BACKSPACE TB_KEY_BACKSPACE
#define TAB TB_KEY_TAB
#define ENTER TB_KEY_ENTER
#define ESCAPE TB_KEY_ESC
#define F1 TB_KEY_F1
#define F2 TB_KEY_F2
#define F3 TB_KEY_F3
#define F4 TB_KEY_F4
#define F5 TB_KEY_F5
#define F6 TB_KEY_F6
#define F7 TB_KEY_F7
#define F8 TB_KEY_F8
#define F9 TB_KEY_F9
#define F10 TB_KEY_F10
#define F11 TB_KEY_F11
#define F12 TB_KEY_F12
#define ARROW_LEFT TB_KEY_ARROW_LEFT
#define ARROW_UP TB_KEY_ARROW_UP
#define ARROW_RIGHT TB_KEY_ARROW_RIGHT
#define ARROW_DOWN TB_KEY_ARROW_DOWN
#define HOME TB_KEY_HOME
#define END TB_KEY_END
#define PAGE_UP TB_KEY_PGUP
#define PAGE_DOWN TB_KEY_PGDN
#define CTRL TB_KEY_CTRL_T
#define ALT TB_KEY_ALT_T
#define ERROR_MESSAGE "NOT ENOUGH ESPACE"

char *archiveText; // ? Is Used to manage the file input


void screenRendering(){

}

void inputRendering(){
    while (1) {

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
