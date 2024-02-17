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
    short xpos = 1;
    bool inCommandMode = true;
    while (inCommandMode)
    {
        switch(event.key) {
            case TB_KEY_ENTER:
                break;
            case TB_KEY_SPACE:
                xpos++;
                tb_change_cell(xpos,0,' ',TB_WHITE,TB_BLACK);
                tb_present();
                break;
            case TB_KEY_ESC:
                inCommandMode = false;
                break;
            case TB_KEY_BACKSPACE:
                xpos--;
                break;
            case 'a':
                xpos++;
                tb_change_cell(xpos,0,'a',TB_WHITE,TB_BLACK);
                tb_present();
                break;
            case 'b':
                xpos++;
                tb_change_cell(xpos,0,'b',TB_WHITE,TB_BLACK);
                tb_present();
                break;
            case 'c':
                xpos++;
                tb_change_cell(xpos,0,'c',TB_WHITE,TB_BLACK);
                tb_present();
                break;
            case 'd':
                break;
            case 'e':
                break;
            case 'f':
                break;
            case 'g':
                break;
            case 'h':
                break;
            case 'i':
                break;
            case 'j':
                break;
            case 'k':
                break; 
            case 'l':
                break; 
            case 'm':
                break; 
            case 'n':
                break; 
            case 'o':
                break; 
            case 'p':
                break; 
            case 'q':
                break; 
            case 'r':
                break; 
            case 's':
                break; 
            case 't':
                break; 
            case 'u':
                break; 
            case 'v':
                break; 
            case 'w':
                break; 
            case 'x':
                break; 
            case 'y':
                break; 
            case 'z':
                break; 
            case 'ñ':
                break; 
            case 'ç':
                break; 
            case 'A':
                break; 
            case 'B':
                break; 
            case 'C':
                break; 
            case 'D':
                break; 
            case 'E':
                break;
            case 'F':
                break;
            case 'G':
                break;
            case 'H':
                break;
            case 'I':
                break;
            case 'J':
                break;
            case 'K':
                break; 
            case 'L':
                break; 
            case 'M':
                break; 
            case 'N':
                break; 
            case 'O':
                break; 
            case 'P':
                break; 
            case 'Q':
                break; 
            case 'R':
                break; 
            case 'S':
                break; 
            case 'T':
                break; 
            case 'U':
                break; 
            case 'V':
                break; 
            case 'W':
                break; 
            case 'X':
                break; 
            case 'Y':
                break; 
            case 'Z':
                break; 
            case 'Ñ':
                break; 
            case 'Ç':
                break;  
            default:
                break; 
        }
    }
    

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

