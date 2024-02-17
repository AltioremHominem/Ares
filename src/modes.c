#include <stdbool.h>
#include <termbox.h>

#include "fileIO.h"

#include "modes.h"

#define WIDTH 80
#define HEIGHT 24
#define CHAR_SPACING 2

short xpos = 1;


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

void commandMode(){ // ? Vim Like Command Mode
    struct tb_event event;
    char *bufferCommand;
    tb_poll_event(&event);
    tb_change_cell(1,0,':',TB_WHITE,TB_BLACK);
    tb_present();
    bool inCommandMode = true;
    while (inCommandMode)
    {   
        xpos = 1;
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
                xpos++;
                tb_change_cell(xpos,0,'d',TB_WHITE,TB_BLACK);
                tb_present();
                break;
            case 'e':
                xpos++;
                tb_change_cell(xpos,0,'e',TB_WHITE,TB_BLACK);
                tb_present();
                break;
            case 'f':
                xpos++;
                tb_change_cell(xpos,0,'f',TB_WHITE,TB_BLACK);
                tb_present();
                break;
            case 'g':
                xpos++;
                tb_change_cell(xpos,0,'g',TB_WHITE,TB_BLACK);
                tb_present();
                break;
            case 'h':
                xpos++;
                tb_change_cell(xpos,0,'h',TB_WHITE,TB_BLACK);
                tb_present();
                break;
            case 'i':
                xpos++;
                tb_change_cell(xpos,0,'i',TB_WHITE,TB_BLACK);
                tb_present();
                break;
            case 'j':
                xpos++;
                tb_change_cell(xpos,0,'j',TB_WHITE,TB_BLACK);
                tb_present();
                break;
            case 'k':
                xpos++;
                tb_change_cell(xpos,0,'k',TB_WHITE,TB_BLACK);
                tb_present();
                break; 
            case 'l':
                xpos++;
                tb_change_cell(xpos,0,'l',TB_WHITE,TB_BLACK);
                tb_present();
                break; 
            case 'm':
                xpos++;
                tb_change_cell(xpos,0,'m',TB_WHITE,TB_BLACK);
                tb_present();
                break; 
            case 'n':
                xpos++;
                tb_change_cell(xpos,0,'n',TB_WHITE,TB_BLACK);
                tb_present();
                break; 
            case 'o':
                xpos++;
                tb_change_cell(xpos,0,'o',TB_WHITE,TB_BLACK);
                tb_present();
                break; 
            case 'p':
                xpos++;
                tb_change_cell(xpos,0,'p',TB_WHITE,TB_BLACK);
                tb_present();
                break; 
            case 'q':
            xpos++;
                tb_change_cell(xpos,0,'q',TB_WHITE,TB_BLACK);
                tb_present();
                break; 
            case 'r':
                xpos++;
                tb_change_cell(xpos,0,'r',TB_WHITE,TB_BLACK);
                tb_present();
                break; 
            case 's':
                xpos++;
                tb_change_cell(xpos,0,'s',TB_WHITE,TB_BLACK);
                tb_present();
                break; 
            case 't':
                xpos++;
                tb_change_cell(xpos,0,'t',TB_WHITE,TB_BLACK);
                tb_present();
                break; 
            case 'u':
                xpos++;
                tb_change_cell(xpos,0,'u',TB_WHITE,TB_BLACK);
                tb_present();
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
    for (short i = 0 ; i < xpos; i++){ // ? End command mode and return to normality
        tb_change_cell(i,0,' ',TB_BLACK,TB_BLACK);
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

