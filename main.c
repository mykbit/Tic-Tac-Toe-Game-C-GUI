#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "start_game.h"
#include "window.h"

int main(int argc, char* argv[]) {

    gtk_init(&argc, &argv);
    //play_game();

    open_window();

    return 0;
}