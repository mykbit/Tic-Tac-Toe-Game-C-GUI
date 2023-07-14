#include "window.h"

void open_window() {
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_title(GTK_WINDOW(window), "Tic Tac Toe");

    g_signal_connect(window, "delete_event", G_CALLBACK(quit_app), NULL);

    GtkWidget *button = gtk_button_new_with_label("Exit");
    g_signal_connect(button, "clicked", G_CALLBACK(quit_app), NULL);
    
    GtkWidget *score_lbl = gtk_label_new("Score\n 0 : 0");

    // create a grid to hold the button and label
    GtkWidget *grid = gtk_grid_new();
    // make both widgets expand to fill the grid
    gtk_widget_set_hexpand(button, TRUE);
    gtk_widget_set_vexpand(button, TRUE);
    gtk_widget_set_hexpand(score_lbl, TRUE);
    gtk_widget_set_vexpand(score_lbl, TRUE);

    // add the widgets to the grid
    gtk_grid_attach(GTK_GRID(grid), score_lbl, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

    // create a separate box for the game board
    GtkWidget *boardBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    // create a box to hold the grid and add it to the window
    GtkWidget *mainBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    // add the grid and boardBox to the main box
    gtk_box_pack_start(GTK_BOX(mainBox), boardBox, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(mainBox), grid, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(window), mainBox);
    gtk_widget_show_all(window);
    gtk_main();
    return;
}

void quit_app(GtkWidget *widget, gpointer ptr) {
    gtk_main_quit();
    return;
}

void draw_score(GtkWidget *widget, gpointer ptr) {
    char buffer[30];

    // TODO: get the score from the game

    printf("Score");
    sprintf(buffer, "%s : %s", X, O);
    gtk_label_set_text(GTK_LABEL(ptr), buffer);
}

char *count_score() {
    // if player 1 wins, increment X
    // if player 2 wins, increment O
    // if draw, do nothing
    // return the score
    return 0;
}