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

void button_click_callback(GtkWidget *widget, gpointer ptr);

void first_move_btn_callback(GtkWidget *widget, gpointer ptr);

void set_next_turn(GtkWidget *turn);

void apply_turn_player(GtkWidget *widget, gpointer ptr);

void apply_widget_position_on_matrix(GtkWidget *widget);

gboolean apply_turn_cpu(gpointer ptr);

void game_result(gpointer ptr, int result);

int check_win(char symbol);

void clean_matrix();

gboolean game_start_text(gpointer user_data);

void draw_score(gpointer ptr, int X, int O);

void cpu_move();

int minimax(char player_symbol, int depth, gboolean is_maximizing);

void cpu_move_impossible(char player_symbol);

void apply_matrix_position_on_widget(int i, int j);