#include "start_game.h"
#include "window.h"

void mode_select() {
    switch(sel_mode) {
        case 1:
            printf("Player vs Player\n");
            //start Player vs Player game
            open_window();
            break;
        case 2:
            printf("Player vs CPU\n");
            open_window();
            break;
        case 3:
            printf("Player vs CPU (Impossible)\n");
            open_window();
            break;
        case 4:
            printf("Exiting the application...\n");
            exit(0);
            break;
        default:
            printf("???\n");
            break;
    }
}

void play_game() {
    printf("Choose the game mode:\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs CPU\n");
    printf("3. Player vs CPU (Impossible)\n");
    printf("4. Exit the application\n");
    printf("Type the corresponding number: ");

    while (1) {
        fgets(input, sizeof(input), stdin);
        char* endptr;
        sel_mode = strtol(input, &endptr, 0);
        if (endptr != input && *endptr == '\n' && sel_mode >= 1 && sel_mode <= 3) {
            break;
        }
        printf("\nInvalid input. Try again\n");
        printf("Type the corresponding number: ");
    }

    mode_select();
}