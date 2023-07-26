#include <gtk/gtk.h>
#include "button_hashtable.h"
#include <math.h>

int sel_mode;
int X;
int O;
char matrix[3][3];
extern char current_symbol;

gboolean game_finished;
gboolean player1_first_move;
gboolean cpu_first_move;
gboolean cpu_turn_flag;

HashTable *table;

GtkWidget *window;
GtkWidget *exit_button;
GtkWidget *score_lbl;
GtkWidget *game_grid;
GtkWidget *restart_btn;
GtkWidget *player1_btn;
GtkWidget *cpu_btn;
GtkWidget *turn_lbl;
gchar *current_turn_string;
gchar *start_game_string;

/*
    Reacts to a game grid button click by a player. Deactivates the button and calls the function to apply the turn.
    If the game is not finished, it sets the next turn. If the game mode is against the CPU, it calls the function to apply the CPU turn.
*/
void button_click_callback(GtkWidget *widget, gpointer ptr);

/*
    Reacts to a "first move" button click by a player. Deactivates both buttons and sets the first turn.
*/
void first_move_btn_callback(GtkWidget *widget, gpointer ptr);

/*
    Sets the next turn based on the current symbol and the game mode.
*/
void set_next_turn(GtkWidget *turn);

/*
    Applies the turn of the player by setting the button label to the current symbol and
    adding the symbol to a correspoding position in the matrix. Then it checks if there is 
    a terminal condition and calls the functions to display the result regardless of the outcome.
*/
void apply_turn_player(GtkWidget *widget, gpointer ptr);

/*
    Retrieves the predefined id of the button, which is converted to a corresponding position in the matrix.
    Then it assigns the current symbol to that position in the matrix.
*/
void apply_widget_position_on_matrix(GtkWidget *widget);

/*
    Depending on the CPU opponent mode, calls the corresponding turn processing functions.
    Then it checks if the game is finished and calls the function to display the result.
    If the game is not finished yet, it sets the next turn.
*/
gboolean apply_turn_cpu(gpointer ptr);

/*
    If the result is anything but -1 (which means no terminal condition has been reached), it checks which game mode
    is enabled and which symbol the player is operating to display the score correctly. Then it displays a winning message
    above the grid. Regardless of the outcome, it sets the game flag as finished and deactivates the game grid.
*/
void game_result(gpointer ptr, int result);

/*
    Checks if a win condition has been reached by a party that is being passed as an argument. 
    -1 is returned if no terminal condition has been reached yet.
*/
int check_win(char symbol);

/*
    Clears the matrix by setting all its values to null characters.
*/
void clean_matrix();

/*
    Operates within a 3 second timeout to display a message above the grid that the game has started.
    Can be interrupted if the player makes a move before the timeout ends.
*/
gboolean game_start_text(gpointer user_data);

/*
    Updates the score label with the current score of the players.
*/
void draw_score(gpointer ptr, int X, int O);

/*
    The function is used if the user has selected the usual CPU opponent mode.
    It checks if the CPU can win in the next move and if it can, it applies the move.
    Then it checks if the player can win in the next move and if it can, it tries to bloack the player.
    If the game is far from end, it applies a random move.
*/
void cpu_move();

/*
    The function is used if the user has selected the impossible CPU opponent mode.
    The difference is that instead of applying a random turn at early phases of the game,
    it simulates the development of the current game and applies the move that will lead to the best outcome.
    This is done by using the minimax algorithm. If a move is decided, it is applied to the game grid.
*/
void cpu_move_impossible(char player_symbol);

/*
    The minimax algorithm is used to simulate the development of the game and apply the move that will lead to the best outcome.
    The algorithm is based on the assumption that both players are playing optimally.
    The function is recursive and it is called for each possible move. It returns the best score for the current player.
*/
int minimax(char player_symbol, int depth, gboolean is_maximizing);

/*
    The function takes the new entry's position in the matrix and looks up the hashtable to find the corresponding button.
    Then it applies the current symbol to the button and deactivates that button.
*/
void apply_matrix_position_on_widget(int i, int j);