#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




char fileInput(char *filename){
    FILE *archive;

    archive = fopen(filename,"r");

    if (archive = NULL) {  // Create Archive if doesn't exist
        archive = fopen(filename,"w");
        return NULL;
    
    } else { // Read Archive
        short character;
        long long length = 0;
        char *charArray;
        charArray = (char *)malloc(2 * sizeof(char));

        while ((character = getchar()) !=  '\n' && character != EOF) {
        charArray = (char *)realloc(charArray, (length + 1) * sizeof(char));
        if (charArray == NULL) {
            exit(1);
        }
        charArray[length++] = (char)character;

    }

    charArray = (char *)realloc(charArray, (length + 1)* sizeof(char) );
        if ( charArray == NULL) {
        exit(1);
    }
    charArray[length] = '\0';
    char fileText[length + 1];
    strncpy(fileText, charArray, length + 1);
    free(charArray);
    }
}



void fileOutput(){



}
