#include "window.h"

void create_game_window() {
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);
    gtk_window_set_title(GTK_WINDOW(window), "Tic Tac Toe");
    window_handler_id = g_signal_connect(window, "delete_event", G_CALLBACK(quit_app), NULL);

    current_turn_string = "Player 1's Turn";
    start_game_string = "Game Start!";

    exit_button = gtk_button_new_with_label("Exit");
    exit_button_handler_id = g_signal_connect(exit_button, "clicked", G_CALLBACK(quit_app), NULL);

    restart_btn = gtk_button_new_with_label("Restart");
    restart_button_handler_id = g_signal_connect(restart_btn, "clicked", G_CALLBACK(restart_game), NULL);
    gtk_widget_set_sensitive(restart_btn, FALSE);

    
    score_lbl = gtk_label_new("");
    draw_score(score_lbl, X, O);

    turn_lbl = gtk_label_new("Game Start!");

    // create a grid to hold the score and exit button
    game_grid = gtk_grid_new();

    // create buttons 3 by 3
    btn11 = gtk_button_new_with_label("\u00B7");
    btn12 = gtk_button_new_with_label("\u00B7");
    btn13 = gtk_button_new_with_label("\u00B7");
    btn21 = gtk_button_new_with_label("\u00B7");
    btn22 = gtk_button_new_with_label("\u00B7");
    btn23 = gtk_button_new_with_label("\u00B7");
    btn31 = gtk_button_new_with_label("\u00B7");
    btn32 = gtk_button_new_with_label("\u00B7");
    btn33 = gtk_button_new_with_label("\u00B7");

    // create signal handlers for the buttons
    btn11_handler_id = g_signal_connect(btn11, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn11), "id", "00");
    btn12_handler_id = g_signal_connect(btn12, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn12), "id", "01");
    btn13_handler_id = g_signal_connect(btn13, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn13), "id", "02");
    btn21_handler_id = g_signal_connect(btn21, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn21), "id", "10");
    btn22_handler_id = g_signal_connect(btn22, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn22), "id", "11");
    btn23_handler_id = g_signal_connect(btn23, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn23), "id", "12");
    btn31_handler_id = g_signal_connect(btn31, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn31), "id", "20");
    btn32_handler_id = g_signal_connect(btn32, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn32), "id", "21");
    btn33_handler_id = g_signal_connect(btn33, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn33), "id", "22");

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
    gtk_widget_set_hexpand(restart_btn, TRUE);
    gtk_widget_set_vexpand(restart_btn, TRUE);

    gtk_grid_attach(GTK_GRID(main_grid), turn_lbl,    0, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(main_grid), game_grid,   0, 1, 1, 10);
    gtk_grid_attach(GTK_GRID(main_grid), score_lbl,   1, 1, 1, 5);
    gtk_grid_attach(GTK_GRID(main_grid), restart_btn, 1, 7, 1, 2);
    gtk_grid_attach(GTK_GRID(main_grid), exit_button, 1, 9, 1, 2);  

    gtk_container_add(GTK_CONTAINER(window), main_grid);
    gtk_widget_show_all(window);
    g_timeout_add_seconds(3, game_start_text, turn_lbl);
}

void open_window() {
    create_game_window();
    gtk_main();
}

void quit_app(GtkWidget *widget, gpointer ptr) {
    gtk_main_quit();
}

void restart_game(GtkWidget *widget, gpointer ptr) {
    turn_count = 0;
    clean_matrix();
    g_signal_handler_disconnect(window, window_handler_id);
    g_signal_handler_disconnect(exit_button, exit_button_handler_id);
    g_signal_handler_disconnect(restart_btn, restart_button_handler_id);
    g_signal_handler_disconnect(btn11, btn11_handler_id);
    g_signal_handler_disconnect(btn12, btn12_handler_id);
    g_signal_handler_disconnect(btn13, btn13_handler_id);
    g_signal_handler_disconnect(btn21, btn21_handler_id);
    g_signal_handler_disconnect(btn22, btn22_handler_id);
    g_signal_handler_disconnect(btn23, btn23_handler_id);
    g_signal_handler_disconnect(btn31, btn31_handler_id);
    g_signal_handler_disconnect(btn32, btn32_handler_id);
    g_signal_handler_disconnect(btn33, btn33_handler_id);

    gtk_widget_destroy(window);
    gtk_main_quit();
    open_window();
}

// Callback function to change the label text
gboolean game_start_text(gpointer user_data) {
    // Retrieve the label widget from the user_data
    GtkWidget *label = GTK_WIDGET(user_data);

    const gchar *s = gtk_label_get_text(GTK_LABEL(label));

    if (g_strcmp0(s, start_game_string) == 0) {
        gtk_label_set_text(GTK_LABEL(label), current_turn_string);
    }
    // Return FALSE to stop the timeout
    return FALSE;
}

void draw_score(gpointer ptr, int X, int O) {
    char buffer[30];

    sprintf(buffer, "Score\n %d : %d", X, O);
    gtk_label_set_text(GTK_LABEL(ptr), buffer);
}

void button_click_callback(GtkWidget *widget, gpointer ptr) {
    turn_count++;
    gtk_widget_set_sensitive(widget, FALSE);
    GtkWidget *turn = GTK_WIDGET(ptr);

    const gchar *turn_text = gtk_label_get_text(GTK_LABEL(turn));
    
    if (g_strcmp0(turn_text, current_turn_string) == 0 || g_strcmp0(turn_text, start_game_string) == 0) {
        current_symbol = 'X';
        gtk_button_set_label(GTK_BUTTON(widget), "X");
        gtk_label_set_text(GTK_LABEL(turn), "Player 2's Turn");
    }
    else {
        current_symbol = 'O';
        gtk_button_set_label(GTK_BUTTON(widget), "O");
        gtk_label_set_text(GTK_LABEL(turn), "Player 1's Turn");
    }
    
    apply_turn(widget, ptr);

}

void apply_turn(GtkWidget *widget, gpointer ptr) {
    apply_widget_position(widget);
    int result = check_win();
    if (result == 1 && current_symbol == 'X') {
        X++;
        gtk_label_set_text(GTK_LABEL(ptr), "Player 1 Wins!");
        gtk_widget_set_sensitive(game_grid, FALSE);
        gtk_widget_set_sensitive(restart_btn, TRUE);
    }
    else if (result == 1 && current_symbol == 'O') {
        O++;
        gtk_label_set_text(GTK_LABEL(ptr), "Player 2 Wins!");
        gtk_widget_set_sensitive(game_grid, FALSE);
        gtk_widget_set_sensitive(restart_btn, TRUE);
    }
    else if (result == 0 && turn_count == 9) {
        gtk_label_set_text(GTK_LABEL(ptr), "Draw!");
        gtk_widget_set_sensitive(game_grid, FALSE);
        gtk_widget_set_sensitive(restart_btn, TRUE);
    }
    draw_score(score_lbl, X, O);
    
}

void apply_widget_position(GtkWidget *widget) {
    char *button_id = g_object_get_data(G_OBJECT(widget), "id");

    int x = button_id[0] - '0';
    int y = button_id[1] - '0';

    matrix[x][y] = current_symbol;
}

int check_win() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == current_symbol && matrix[i][1] == current_symbol && matrix[i][2] == current_symbol) {
            return 1; // Winning combination found
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (matrix[0][j] == current_symbol && matrix[1][j] == current_symbol && matrix[2][j] == current_symbol) {
            return 1; // Winning combination found
        }
    }

    // Check diagonals
    if ((matrix[0][0] == current_symbol && matrix[1][1] == current_symbol && matrix[2][2] == current_symbol) ||
        (matrix[0][2] == current_symbol && matrix[1][1] == current_symbol && matrix[2][0] == current_symbol)) {
        return 1; // Winning combination found
    }

    if (turn_count == 9) {
        return 0; // Draw
    }

    else return -1; // No winning combination found yet
}

void clean_matrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = ' ';
        }
    }
}
