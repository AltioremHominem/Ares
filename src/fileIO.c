#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fileIO.h"



void fileInput(char *filename){ // ? Open Archive
    FILE *archive;

    archive = fopen(filename,"a+"); // ? Read Archive, if it doesn't exist, creates it

    if ( archive == NULL ) { // ? Create Archive


    } else { // ? Read Archive and all the text comes to the memory (dinamic memory management)
        int character;
        long long length = 0;
        char *charArray;
        charArray = (char *)malloc(2 * sizeof(char));

        while ((character = getchar()) !=  '\n' && character != EOF) {
        charArray = (char *)realloc(charArray, (length + 1) * sizeof(char));
        if (charArray == NULL) {
            free(charArray);
            exit(1);
        }
        charArray[length++] = (char)character;

    }

    charArray = (char *)realloc(charArray, (length + 1)* sizeof(char) );
        if ( charArray == NULL) {
            free(charArray);
        exit(1);
    }
    charArray[length] = '\0';
    char fileText[length + 1];
    strncpy(fileText, charArray, length + 1);
    free(charArray);
    }
}

void fileOutput(char *filename, char *fileText){ // ? Write Changes
    FILE *archive = fopen(filename, "a");
    if (archive == NULL) {
        exit(1);
    }
    fputs(fileText,archive);
    fclose(archive);
}
