#include "game_logic.h"
#include "variables.h"

gboolean game_finished = FALSE;
gboolean player1_first_move = FALSE;
gboolean cpu_first_move = FALSE;

void button_click_callback(GtkWidget *widget, gpointer ptr) {
    gtk_widget_set_sensitive(widget, FALSE);
    apply_turn_player(widget, ptr);
    if (!game_finished) {
        set_next_turn(GTK_WIDGET(ptr));
        if (sel_mode >= 2) {
            gtk_widget_set_sensitive(game_grid, FALSE);
            g_timeout_add(1000, apply_turn_cpu, ptr);
        }
    }
}

void first_move_btn_callback(GtkWidget *widget, gpointer ptr) {    
    gtk_widget_set_sensitive(player1_btn, FALSE);
    gtk_widget_set_sensitive(cpu_btn, FALSE);

    char *button_id = g_object_get_data(G_OBJECT(widget), "id");
    if (button_id[0] == '1') {
        gtk_label_set_text(GTK_LABEL(ptr), "Player 1's Turn");
        gtk_widget_set_sensitive(game_grid, TRUE);
        player1_first_move = TRUE;
    }
    else {
        gtk_label_set_text(GTK_LABEL(ptr), "CPU's Turn");
        cpu_first_move = TRUE;
        gtk_widget_set_sensitive(game_grid, FALSE);
        g_timeout_add(1000, apply_turn_cpu, ptr);
    }
}

void set_next_turn(GtkWidget *turn) {
    const gchar *turn_text = gtk_label_get_text(GTK_LABEL(turn));
    if (current_symbol == 'X') {
        current_symbol = 'O';
        if (sel_mode >= 2) {
            if (g_strcmp0(turn_text, "Player 1's Turn") == 0) {
                gtk_label_set_text(GTK_LABEL(turn), "CPU's Turn");
            }
            else {
                gtk_label_set_text(GTK_LABEL(turn), "Player 1's Turn");
            }
        }
        else {
            gtk_label_set_text(GTK_LABEL(turn), "Player 2's Turn");
        }
    }
    else if (current_symbol == 'O') {
        current_symbol = 'X';
        if (sel_mode >= 2) {
            if (g_strcmp0(turn_text, "CPU's Turn") == 0) {
                gtk_label_set_text(GTK_LABEL(turn), "Player 1's Turn");
            }
            else {
                gtk_label_set_text(GTK_LABEL(turn), "CPU's Turn");
            }
        }
        else {
            gtk_label_set_text(GTK_LABEL(turn), "Player 1's Turn");
        }
    }
}

void apply_turn_player(GtkWidget *widget, gpointer ptr) {
    gtk_button_set_label(GTK_BUTTON(widget), &current_symbol);
    apply_widget_position_on_matrix(widget);
    int result = check_win(current_symbol);
    game_result(ptr, result);
    draw_score(score_lbl, X, O);
}

void apply_widget_position_on_matrix(GtkWidget *widget) {
    char *button_id = g_object_get_data(G_OBJECT(widget), "id");

    int x = button_id[0] - '0';
    int y = button_id[1] - '0';

    matrix[x][y] = current_symbol;
}

gboolean apply_turn_cpu(gpointer ptr) {
    if (sel_mode == 2) {
        cpu_move();
    }
    else {
        cpu_move_impossible(current_symbol);
    }
    int result = check_win(current_symbol);
    game_result(ptr, result);
    draw_score(score_lbl, X, O);
    if (!game_finished) {
        set_next_turn(GTK_WIDGET(ptr));
        gtk_widget_set_sensitive(game_grid, TRUE);
    }
    return FALSE;
}

void game_result(gpointer ptr, int result) {
    if (result != -1) {
        gtk_widget_set_sensitive(game_grid, FALSE);
        gtk_widget_set_sensitive(restart_btn, TRUE);

        const gchar *playerLabel = "Player 1 Wins!";
        const gchar *player2Label = "Player 2 Wins!";
        const gchar *cpuLabel = "CPU Wins!";
        gboolean isCPUTurn = g_strcmp0(gtk_label_get_text(GTK_LABEL(ptr)), "CPU's Turn") == 0;

        if (result == 0) {
            gtk_label_set_text(GTK_LABEL(ptr), "Draw!");
        }
        else {
            if (sel_mode >= 2) {
                if ((current_symbol == 'X' && player1_first_move) || (current_symbol == 'O' && cpu_first_move)) {
                    X++;
                    gtk_label_set_text(GTK_LABEL(ptr), isCPUTurn ? cpuLabel : playerLabel);
                }
                else {
                    O++;
                    gtk_label_set_text(GTK_LABEL(ptr), isCPUTurn ? cpuLabel : playerLabel);
                }
            }
            else {
                if (current_symbol == 'X') {
                    X++;
                    gtk_label_set_text(GTK_LABEL(ptr), playerLabel);
                }
                else {
                    O++;
                    gtk_label_set_text(GTK_LABEL(ptr), player2Label);
                }
            }
        }
        game_finished = TRUE;
        gtk_widget_set_sensitive(game_grid, FALSE);
    }
}

int check_win(char symbol) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == symbol && matrix[i][1] == symbol && matrix[i][2] == symbol) {
            return 1; // Winning combination found
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (matrix[0][j] == symbol && matrix[1][j] == symbol && matrix[2][j] == symbol) {
            return 1; // Winning combination found
        }
    }

    // Check diagonals
    if ((matrix[0][0] == symbol && matrix[1][1] == symbol && matrix[2][2] == symbol) ||
        (matrix[0][2] == symbol && matrix[1][1] == symbol && matrix[2][0] == symbol)) {
        return 1; // Winning combination found
    }

    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            if (matrix[i][j]=='\0') {
                return -1; // No winning combination found yet and some tiles are still empty
            }
        }
    }
    return 0; // Draw
}

void clean_matrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = '\0';
        }
    }
}

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

void draw_score(gpointer ptr, int score_X, int score_O) {
    char buffer[30];
    sprintf(buffer, "Score\n %d : %d", score_X, score_O);
    gtk_label_set_text(GTK_LABEL(ptr), buffer);
}

void cpu_move() {
    // Check if computer can win in the next move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == '\0') {
                matrix[i][j] = current_symbol;
                if (check_win(current_symbol) == 1) {
                    apply_matrix_position_on_widget(i, j);
                    return; // Computer wins
                }
                matrix[i][j] = '\0';
            }
        }
    }

    // Check if player can win in the next move, and block them
    char player_symbol = (current_symbol == 'X') ? 'O' : 'X';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == '\0') {
                matrix[i][j] = player_symbol;
                if (check_win(player_symbol) == 1) {
                    matrix[i][j] = current_symbol;
                    apply_matrix_position_on_widget(i, j);
                    return; // Computer blocks
                }
                matrix[i][j] = '\0';
            }
        }
    }

    // Choose a random available position
    int num_empty = 0;
    int empty_positions[3 * 3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == '\0') {
                empty_positions[num_empty++] = i * 3 + j;
            }
        }
    }
    if (num_empty == 0) {
        return; // No available positions
    }
    int random_index = rand() % num_empty;
    int position = empty_positions[random_index];
    int row = position / 3;
    int col = position % 3;
    matrix[row][col] = current_symbol;
    apply_matrix_position_on_widget(row, col);
}

void cpu_move_impossible(char player_symbol) {
    int best_score = -100000;
    int row = -1;
    int col = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == '\0') {
                matrix[i][j] = player_symbol;
                int move_score = minimax(player_symbol, 0, FALSE);
                matrix[i][j] = '\0';
                if (move_score > best_score)
                {
                    row = i;
                    col = j;
                    best_score = move_score;
                }
            }
        }
    }
    matrix[row][col] = player_symbol;
    apply_matrix_position_on_widget(row, col);
}

int minimax(char player_symbol, int depth, gboolean is_maximizing) {
    char opponent_symbol = (player_symbol == 'X') ? 'O' : 'X';
    int result = 0;
    if (check_win(player_symbol) == 1) {
        return result + 9 - depth;
    }
    else if (check_win(opponent_symbol) == 1) {
        return result - 11 + depth;
    }
    else if (check_win(player_symbol) == 0 || check_win(opponent_symbol) == 0) {
        return result;
    }

    int best_score = is_maximizing ? -10000 : 10000;
    int score;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == '\0') {
                matrix[i][j] = is_maximizing ? player_symbol : opponent_symbol;
                score = minimax(player_symbol, depth + 1, !is_maximizing);
                matrix[i][j] = '\0';

                if ((is_maximizing && score > best_score) || (!is_maximizing && score < best_score)) {
                    best_score = score;
                }
            }
        }
    }
    return best_score;
}

void apply_matrix_position_on_widget(int i, int j) {
    char buffer[3];
    sprintf(buffer, "%d%d", i, j);
    GtkWidget *retrieved_button = hash_table_lookup(table, buffer);
    gtk_button_set_label(GTK_BUTTON(retrieved_button), &current_symbol);
    gtk_widget_set_sensitive(retrieved_button, FALSE);
}