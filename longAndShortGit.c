/*
 *  MADISON LANDIS 
 *  10.05.2025
 *  CS-46: SYSTEM PROGRAMMING 
 *  --------------------------
 *  Warm-Up 7.2: Long and Short
 *  > Working with long and short
 // ------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // check if enough arguments in file
    if(argc < 4) {
        printf("Please enter one file to read and two files to write to.\n");
        exit(1);
    }

    // get pointers to file arguments 

    // file one
    FILE * fileOne = fopen(argv[1], "r");
    if(!fileOne) {
        printf("Could not open: %s\n", argv[1]);
        exit(1);
    }

    // file two
    FILE * fileTwo = fopen(argv[2], "w");
    if(!fileTwo) {
        printf("Could not open: %s\n", argv[2]);
        exit(1);
    }

    // file three
    FILE * fileThree = fopen(argv[3], "w");
    if(!fileThree) {
        printf("Could not open: %s\n", argv[3]);
        exit(1);
    }

    // create variables to hold information 
    char line[1000];
    int writeCountOne = 0;
    int writeCountTwo = 0;

    // fprintf information to certain files based on line size 
    while(fgets(line, 1000, fileOne) != NULL) {

        int length = strlen(line);

        if(length < 20) {
            for(int i = 0; line[i] != '\0'; i++)
                line[i] = toupper(line[i]);
            fprintf(fileTwo, "%s", line);
            writeCountOne++;
        } else {
            for(int i = 0; line[i] != '\0'; i++)
                line[i] = tolower(line[i]);
            fprintf(fileThree, "%s", line);
            writeCountTwo++;
        }

    }

    // print information about files and close files 
    printf("\n%d lines written to %s!\n", writeCountOne, argv[2]);
    printf("%d lines written to %s!\n\n", writeCountTwo, argv[3]);

    fclose(fileOne);
    fclose(fileTwo);
    fclose(fileThree);

    return 0;
}
