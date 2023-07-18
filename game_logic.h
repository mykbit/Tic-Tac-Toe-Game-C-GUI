#include <gtk/gtk.h>

int turn_count;
char current_symbol;
int X;
int O;
char matrix[3][3];

GtkWidget *window;
GtkWidget *exit_button;
GtkWidget *score_lbl;
GtkWidget *game_grid;
GtkWidget *restart_btn;
gchar *current_turn_string;
gchar *start_game_string;

void restart_game(GtkWidget *widget, gpointer ptr);

void button_click_callback(GtkWidget *widget, gpointer ptr);

void apply_turn(GtkWidget *widget, gpointer ptr);

void apply_widget_position_on_matrix(GtkWidget *widget);

int check_win();

void clean_matrix();

gboolean game_start_text(gpointer user_data);

void draw_score(gpointer ptr, int X, int O);