#include "game.h"

char input[MAX_LENGTH];
int parsed_value;

// void player_vs_player() {

// }


void mode_select(int value) {
    if (parsed_value == 1) {
        // Start Player vs Player
        printf("Starting Player vs Player...\n");
        //player_vs_player();
    }
    else if (parsed_value == 2) {
        // Start Player vs CPU
        printf("Starting Player vs CPU...\n");
        //player_vs_cpu();
    }
}

int input_evaluate(char *input) {
    while(!(sscanf(input, "%d", &parsed_value) == 1 && parsed_value < 3 && parsed_value > 0)) {
        printf("\nInvalid input. Try again\n");
        printf("Type the corresponding number: ");
        fgets(input, sizeof(input), stdin);
    }
    printf("Input: %d\n", parsed_value);
    return parsed_value;
}

void play_game() {
    printf("Choose the game mode:\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs CPU\n");
    printf("Type the corresponding number: ");
    fgets(input, sizeof(input), stdin);

    parsed_value = input_evaluate(input);

    mode_select(parsed_value);
}



