#include <stdbool.h>
#include <stdlib.h>

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



void screenRendering(char *archiveText){
    for (long long i = 0; i < sizeof(archiveText);i++){



    }


}

void startRenderTermBox(char *filename){
    tb_init();         //TermBox Functions


    if (filename == NULL) {

    
    } else {
    char *archiveText;
    archiveText=(char *)malloc(1 * sizeof(fileInput(filename)));
    screenRendering(archiveText);
    free(archiveText);
    }

}


void finishRenderTermBox(){
    tb_shutdown();   //TermBox End Function
}
