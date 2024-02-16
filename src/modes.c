#include <stdbool.h>
#include <termbox.h>

#include "fileIO.h"

#include "modes.h"

#define WIDTH 80
#define HEIGHT 24
#define CHAR_SPACING 2



void insertMode(){ // ? Character Insert
    int cursor_x = 0;
    int cursor_y = 0;
    struct tb_event event;
    tb_poll_event(&event);
    while (1) {
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
                    break;
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

void normalMode(){  // ? Cursor movement and other modes 
    int cursor_x = 0;
    int cursor_y = 0;
    tb_set_cursor(0,0);
    struct tb_event event;
    tb_poll_event(&event);
    while (1){
    switch (event.key)  {  
        case 'i':
            tb_present();
            insertMode();
            break;
        case  ':':
            tb_present();
            commandMode();
            break;
        case  'h':            
            cursor_x++;
            tb_set_cursor(cursor_x,cursor_y);
            tb_present();
            break;
        case  'j':
            cursor_x--;
            tb_set_cursor(cursor_x,cursor_y);
            tb_present();
            break;
        case  'k':
            cursor_y--;
            tb_set_cursor(cursor_x,cursor_y);
            tb_present();
            break;
        case  'l':
            cursor_y++;
            tb_set_cursor(cursor_x,cursor_y);
            tb_present();
            break;   
        default:
            break;
        }
    }
}

