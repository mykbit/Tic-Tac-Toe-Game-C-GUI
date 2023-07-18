#include <gtk/gtk.h>

int sel_mode;
int turn_count;
int X;
int O;
char matrix[3][3];
char current_symbol;
gboolean game_finished;

GtkWidget *window;
GtkWidget *exit_button;
GtkWidget *score_lbl;
GtkWidget *game_grid;
GtkWidget *restart_btn;
GtkWidget *player1_btn;
GtkWidget *cpu_btn;
gchar *current_turn_string;
gchar *start_game_string;

void button_click_callback(GtkWidget *widget, gpointer ptr);

void first_move_btn_callback(GtkWidget *widget, gpointer ptr);

void set_next_turn(GtkWidget *turn);

void apply_turn(GtkWidget *widget, gpointer ptr);

void apply_widget_position_on_matrix(GtkWidget *widget);

void game_result(gpointer ptr, int result);

int check_win();

void clean_matrix();

gboolean game_start_text(gpointer user_data);

void draw_score(gpointer ptr, int X, int O);