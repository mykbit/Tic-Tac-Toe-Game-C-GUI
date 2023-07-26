#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

extern int sel_mode;
char input[MAX_LENGTH];

// Selects the game mode based on the user input
void mode_select();

// Accepts the user input and calls the function to select the game mode
void play_game();
