#include "game.h"

char input[MAX_LENGTH];
int parsed_value;

// void player_vs_player() {

// }


void mode_select(int value) {
    switch(parsed_value) {
        case 1:
            printf("Player vs Player\n");
            //start Player vs Player game
            break;
        case 2:
            printf("Player vs CPU\n");
            //start Player vs CPU game
            break;
        case 3:
            printf("Exiting the application...\n");
            // close the application
            exit(0);
        default:
            printf("???\n");
            break;
    }
}

void play_game() {
    printf("Choose the game mode:\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs CPU\n");
    printf("3. Exit the application\n");
    printf("Type the corresponding number: ");

    while (1) {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &parsed_value) == 1 && parsed_value >= 1 && parsed_value <= 3) {
            break;
        }
        printf("\nInvalid input. Try again\n");
        printf("Type the corresponding number: ");
    }

    mode_select(parsed_value);
}



