/******************************************************************************
** Student name: Kevin Wong
** Student number: s3603055
** Course:          Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "helpers.h"

#define LINE_LEN 80 
#define DELIMS ", "

void readRestOfLine() {
    int ch;
    while (ch = getc(stdin), ch != EOF && ch != '\n') 
    { } /* Gobble each character. */

    /* Reset the error status of the stream. */
    clearerr(stdin);
}

/*Checking if user entry is a valid string, and stored temporarily if correctly entered*/
char * validateString(){
    char line[LINE_LEN + EXTRA_SPACES];
    char *endptr = malloc(strlen(line) + EXTRA_SPACES);

    printf("Please enter your choice:");
    fgets(line, LINE_LEN + EXTRA_SPACES, stdin);

    if(line[strlen(line) - 1] != '\n'){
        readRestOfLine();
    }

    line[strlen(line) - 1] = 0;
    line[strcspn(line, "\n")] = 0 ;
    strcpy(endptr, line);

    return endptr;

}

/*Checking if user entry is a valid integer, and stored temporarily if correctly entered*/
int validateInteger() {
    char line[LINE_LEN + EXTRA_SPACES];
    char *endptr;
    int entry;
    
    do {
        printf("Please enter your choice:");
        fgets(line, LINE_LEN + EXTRA_SPACES, stdin);

        if (line[strlen(line) - 1] != '\n') {
            readRestOfLine();
            continue;
        }

        line[strlen(line) - 1] = 0;
        entry = strtol(line, &endptr, 0);
    }
    while(*endptr);
    return entry;
}


