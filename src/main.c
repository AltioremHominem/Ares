#include <stdio.h>
#include <getopt.h>

#include "rendering.h"

#define VERSION_INFO " Version 0.0.1 "

#define HELP_INFO " -h for help , -v for version "

#define ERROR_INFO " ERROR: Bad Character Given."

static struct option long_options[] = {
        {"help",no_argument, 0, 'h'},
        {"version",no_argument, 0, 'h'},
        {0,0,0,0}
};

int main(int argc, char  **argv){
    int opt;
    int opt_index = 0;
    if (argc == 0) {
        startTermBox(NULL); //rendering.c Function

    } else {
        if (optind < argc) { // If is there a filename to parse
            char *filename;
            filename = argv[optind];
            for(int i=0;filename[i] != '\0' ; i++) {
                if (filename[i] == '*' || filename[i] == '?' || filename[i] == '/' || filename[i] == '\\' ||
                    filename[i] == '<' || filename[i] == '>' || filename[i] == ':' || filename[i] == '|' ||
                    filename[i] == '"' || filename[i] == '\'' || filename[i] == ';' || filename[i] == ',' ||
                    filename[i] == '=') {
                    printf(ERROR_INFO);
                    return 1;
                } else {
                    startTermBox(filename); //rendering.c Function but calling an IO
                }
            }
    }
        char *filename;
        while ((opt = getopt_long(argc, argv, "hv",long_options, &opt_index)) != -1) {
            switch(opt){
                case 'h':
                    printf(HELP_INFO);
                    return 0;
                case 'v':
                    printf(VERSION_INFO);
                    return 0;
                case '?': // Future Arguments Preparation Parsing
                    filename = argv[1];
                    for(int i=0;filename[i] != '\0' ; i++) {
                        if(filename[i] == '*' || filename[i] == '?' || filename[i] == '/' || filename[i] == '\\' || filename[i] == '<' || filename[i] == '>' || filename[i] == ':' || filename[i] == '|' || filename[i] == '"' || filename[i] == '\'' || filename[i] == ';' || filename[i] == ',' || filename[i] == '=' ){
                            printf(ERROR_INFO);
                        return 1;
                        } else {
                    startTermBox(filename); //rendering.c Function but calling an IO
            }
                    }
                    break;
                    default:
                    break;
        
            }
        }
    }



    return 0;
}
