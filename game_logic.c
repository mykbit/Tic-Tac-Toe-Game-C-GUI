#include "game_logic.h"

void button_click_callback(GtkWidget *widget, gpointer ptr) {
    turn_count++;
    gtk_widget_set_sensitive(widget, FALSE);
    GtkWidget *turn = GTK_WIDGET(ptr);

    const gchar *turn_text = gtk_label_get_text(GTK_LABEL(turn));
    
    if (g_strcmp0(turn_text, current_turn_string) == 0 || g_strcmp0(turn_text, start_game_string) == 0) {
        current_symbol = 'X';
        gtk_button_set_label(GTK_BUTTON(widget), "X");
        gtk_label_set_text(GTK_LABEL(turn), "Player 2's Turn");
        // TODO: engage AI
    }
    else {
        current_symbol = 'O';
        gtk_button_set_label(GTK_BUTTON(widget), "O");
        gtk_label_set_text(GTK_LABEL(turn), "Player 1's Turn");
    }
    
    apply_turn(widget, ptr);

}

void apply_turn(GtkWidget *widget, gpointer ptr) {
    apply_widget_position_on_matrix(widget);
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

void apply_widget_position_on_matrix(GtkWidget *widget) {
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