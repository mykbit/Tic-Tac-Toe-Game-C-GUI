#include <gtk/gtk.h>

#define MAX_LENGTH 256

int X;
int O;
char current_symbol;
int turn_count;
char matrix[3][3];

void open_window();

void quit_app(GtkWidget *widget, gpointer ptr);

gboolean game_start_text(gpointer user_data);

void draw_score(GtkWidget *widget, gpointer ptr, int X, int O);

char *count_score();

void button_click_callback(GtkWidget *widget, gpointer ptr);

void apply_turn(GtkWidget *widget, gpointer ptr);

void apply_widget_position(GtkWidget *widget);

void print_matrix();

int check_win();