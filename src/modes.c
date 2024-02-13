#include <stdbool.h>
#include <termbox.h>

#include "fileIO.h"

#include "modes.h"

#define WIDTH 80
#define HEIGHT 24
#define CHAR_SPACING 2

#define UP 1
#define DOWN 2
#define RIGTH 3
#define LEFT 3

void moveCursor(short movementCursor){


}

void insertMode(){ // ? Character Insert
    bool running = true;
    int cursor_x = 0;
    int cursor_y = 0;
    struct tb_event event;
    tb_poll_event(&event);
    while (running) {
        tb_present();
        switch (event.type) { // ? This manages the insert mode and the input of characteres
            case TB_EVENT_KEY:
                if (event.ch >= 32 && event.ch <= 126) {
                    tb_change_cell(cursor_x * (CHAR_SPACING + 1), cursor_y, event.ch, TB_WHITE, TB_DEFAULT);
                    cursor_x++;
                } else if (event.key == TB_KEY_BACKSPACE && cursor_x > 0) {
                    cursor_x--;
                    tb_change_cell(cursor_x * (CHAR_SPACING + 1), cursor_y, ' ', TB_WHITE, TB_DEFAULT);
                } else if (event.key == TB_KEY_ENTER) {
                    cursor_x = 0;
                    cursor_y++;
                } else if (event.key == TB_KEY_ESC ) {
                    running = false;
                }
                cursor_x = (cursor_x + WIDTH) % WIDTH;
                cursor_y = (cursor_y + HEIGHT) % HEIGHT;
                break;
        }
    }
}

void commandMode(){ // ! WIP
    struct tb_event event;
    tb_poll_event(&event);


}

void normalMode(){  // ! WIP
    struct tb_event event;
    tb_poll_event(&event);
    switch (event.key){
    case 'i':
        tb_present();
        insertMode();
        break;
    case  ':':
        tb_present();
        commandMode();
        break;
    case  'h': 
        break;
    case  'j':
        break;
    case  'k':
        break;
    case  'l':
        break;   
    default:
        break;
    }

}

