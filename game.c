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

int invalid_input() {
    bool invalid = true;
    while (invalid) {
        printf("\nInvalid input. Try again\n");
        printf("Type the corresponding number: ");
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%d", &parsed_value) == 1 && parsed_value < 3) {
            return parsed_value;
        }
    }
    return 0;
}

void play_game() {
    printf("Choose the game mode:\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs CPU\n");
    printf("Type the corresponding number: ");
    fgets(input, sizeof(input), stdin);

    if (!(sscanf(input, "%d", &parsed_value) == 1 && parsed_value < 3)) {
        parsed_value = invalid_input();
    }

    mode_select(parsed_value);
}



