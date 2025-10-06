/*
 *  MADISON LANDIS 
 *  10.01.2025
 *  CS-46: SYSTEM PROGRAMMING 
 *  --------------------------
 *  Warm-Up 7.1: Band Name
 *  > using new string functions, manipulate string
 *  inputs and display modified arrays
 // ------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trim(char *s) {

    char *nl = strchr(s, '\n');
    if(nl) *nl = '\0';

}

void trimSize(char s[], int size) {
    s[size] = '\0';
}

int main() {

    printf("-------------------------------------------------\n");

    char inputOne[50];
    char inputTwo[50];
    char inputThree[50];

    // input three strings
    printf("Please enter your favorite color: ");
    fgets(inputOne, 50, stdin);

    printf("Please enter your favorite snack: ");
    fgets(inputTwo, 50, stdin);

    printf("Please enter your favorite animal: ");
    fgets(inputThree, 50, stdin);

    printf("-------------------------------------------------\n");

    // string manipulation
    char colorSnack[50];
    char colorAnimal[50];
    char combo[50];
    strcpy(combo, "");

    // color snack string
    strcpy(colorSnack, inputOne);
    trim(colorSnack);
    strcat(colorSnack, " ");
    strcat(colorSnack, inputTwo);
    trim(colorSnack);

    // color animal string
    strcpy(colorAnimal, inputOne);
    trim(colorAnimal);
    strcat(colorAnimal, " ");
    strcat(colorAnimal, inputThree);
    trim(colorAnimal);
    
    // print first two strings
    printf("Get the new snack %s!\n", colorSnack);
    printf("Featuring newly discovered %ss!\n", colorAnimal);

    // manipulate for combo array
    trimSize(inputTwo, 3);
    trimSize(inputThree, 2);

    strcat(combo, inputTwo);
    inputThree[0] = tolower(inputThree[0]);
    strcat(combo, inputThree);

    // print combo array
    printf("Wait for it. Opening this set is the %ss!!!!\n", combo);

    printf("-------------------------------------------------\n");
    return 0;

}