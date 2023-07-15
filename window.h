#include <gtk/gtk.h>

#define MAX_LENGTH 256

char X[MAX_LENGTH];
char O[MAX_LENGTH];

void open_window();

void quit_app(GtkWidget *widget, gpointer ptr);

void draw_score(GtkWidget *widget, gpointer ptr);

char *count_score();

void test_click_func(GtkWidget *widget, gpointer ptr);