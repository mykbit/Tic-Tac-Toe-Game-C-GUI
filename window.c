#include "window.h"

void open_window() {
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);
    gtk_window_set_title(GTK_WINDOW(window), "Tic Tac Toe");
    g_signal_connect(window, "delete_event", G_CALLBACK(quit_app), NULL);

    GtkWidget *exit_button = gtk_button_new_with_label("Exit");
    g_signal_connect(exit_button, "clicked", G_CALLBACK(quit_app), NULL);
    
    GtkWidget *score_lbl = gtk_label_new("Score\n 0 : 0");

    GtkWidget *turn_lbl = gtk_label_new("Game Start!");

    // create a grid to hold the score and exit button
    GtkWidget *game_grid = gtk_grid_new();

    // create buttons 3 by 3
    GtkWidget *btn11 = gtk_button_new_with_label("\u00B7");
    GtkWidget *btn12 = gtk_button_new_with_label("\u00B7");
    GtkWidget *btn13 = gtk_button_new_with_label("\u00B7");
    GtkWidget *btn21 = gtk_button_new_with_label("\u00B7");
    GtkWidget *btn22 = gtk_button_new_with_label("\u00B7");
    GtkWidget *btn23 = gtk_button_new_with_label("\u00B7");
    GtkWidget *btn31 = gtk_button_new_with_label("\u00B7");
    GtkWidget *btn32 = gtk_button_new_with_label("\u00B7");
    GtkWidget *btn33 = gtk_button_new_with_label("\u00B7");

    // create signal handlers for the buttons
    g_signal_connect(btn11, "clicked", G_CALLBACK(test_click_func), NULL);
    g_signal_connect(btn12, "clicked", G_CALLBACK(test_click_func), NULL);
    g_signal_connect(btn13, "clicked", G_CALLBACK(test_click_func), NULL);
    g_signal_connect(btn21, "clicked", G_CALLBACK(test_click_func), NULL);
    g_signal_connect(btn22, "clicked", G_CALLBACK(test_click_func), NULL);
    g_signal_connect(btn23, "clicked", G_CALLBACK(test_click_func), NULL);
    g_signal_connect(btn31, "clicked", G_CALLBACK(test_click_func), NULL);
    g_signal_connect(btn32, "clicked", G_CALLBACK(test_click_func), NULL);
    g_signal_connect(btn33, "clicked", G_CALLBACK(test_click_func), NULL);

    // make widgets expand to fill the grid
    gtk_widget_set_hexpand(btn11, TRUE);
    gtk_widget_set_vexpand(btn11, TRUE);
    gtk_widget_set_hexpand(btn12, TRUE);
    gtk_widget_set_vexpand(btn12, TRUE);
    gtk_widget_set_hexpand(btn13, TRUE);
    gtk_widget_set_vexpand(btn13, TRUE);
    gtk_widget_set_hexpand(btn21, TRUE);
    gtk_widget_set_vexpand(btn21, TRUE);
    gtk_widget_set_hexpand(btn22, TRUE);
    gtk_widget_set_vexpand(btn22, TRUE);
    gtk_widget_set_hexpand(btn23, TRUE);
    gtk_widget_set_vexpand(btn23, TRUE);
    gtk_widget_set_hexpand(btn31, TRUE);
    gtk_widget_set_vexpand(btn31, TRUE);
    gtk_widget_set_hexpand(btn32, TRUE);
    gtk_widget_set_vexpand(btn32, TRUE);
    gtk_widget_set_hexpand(btn33, TRUE);
    gtk_widget_set_vexpand(btn33, TRUE);
    
    // add the buttons to the grid
    gtk_grid_attach(GTK_GRID(game_grid), btn11, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn12, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn13, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn21, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn22, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn23, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn31, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn32, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn33, 2, 2, 1, 1);


    // create a grid to hold the button and label
    GtkWidget *main_grid = gtk_grid_new();
    // make the widgets expand to fill the grid
    gtk_widget_set_hexpand(exit_button, TRUE);
    gtk_widget_set_vexpand(exit_button, TRUE);
    gtk_widget_set_hexpand(score_lbl, TRUE);
    gtk_widget_set_vexpand(score_lbl, TRUE);
    gtk_widget_set_hexpand(turn_lbl, TRUE);
    gtk_widget_set_vexpand(turn_lbl, TRUE);

    gtk_grid_attach(GTK_GRID(main_grid), turn_lbl,    0, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(main_grid), game_grid,   0, 1, 1, 10);
    gtk_grid_attach(GTK_GRID(main_grid), score_lbl,   1, 1, 1, 7);
    gtk_grid_attach(GTK_GRID(main_grid), exit_button, 1, 9, 1, 2);  

    gtk_container_add(GTK_CONTAINER(window), main_grid);
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

void test_click_func(GtkWidget *widget, gpointer ptr) {
    gtk_button_set_label(GTK_BUTTON(widget), "X");
}