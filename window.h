#include <gtk/gtk.h>

#define MAX_LENGTH 256

int X;
int O;
char current_symbol;
int turn_count;
char matrix[3][3];
GtkWidget *window;
GtkWidget *exit_button;
GtkWidget *score_lbl;
GtkWidget *game_grid;
GtkWidget *restart_btn;
GtkWidget *turn_lbl;
gchar *current_turn_string;
gchar *start_game_string;
GtkWidget *btn11;
GtkWidget *btn12;
GtkWidget *btn13;
GtkWidget *btn21;
GtkWidget *btn22;
GtkWidget *btn23;
GtkWidget *btn31;
GtkWidget *btn32;
GtkWidget *btn33;

gulong window_handler_id;
gulong exit_button_handler_id;
gulong restart_button_handler_id;
gulong btn11_handler_id;
gulong btn12_handler_id;
gulong btn13_handler_id;
gulong btn21_handler_id;
gulong btn22_handler_id;
gulong btn23_handler_id;
gulong btn31_handler_id;
gulong btn32_handler_id;
gulong btn33_handler_id;

void open_window();

void quit_app(GtkWidget *widget, gpointer ptr);

void restart_game(GtkWidget *widget, gpointer ptr);

gboolean game_start_text(gpointer user_data);

void draw_score(gpointer ptr, int X, int O);

char *count_score();

void button_click_callback(GtkWidget *widget, gpointer ptr);

void apply_turn(GtkWidget *widget, gpointer ptr);

void apply_widget_position(GtkWidget *widget);

void print_matrix();

int check_win();

void clean_matrix();