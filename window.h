#include <gtk/gtk.h>

#define MAX_LENGTH 256

char X[MAX_LENGTH];
char O[MAX_LENGTH];

GtkWidget *box11;
GtkWidget *box12;
GtkWidget *box13;
GtkWidget *box21;
GtkWidget *box22;
GtkWidget *box23;
GtkWidget *box31;
GtkWidget *box32;
GtkWidget *box33;

void open_window();

void quit_app(GtkWidget *widget, gpointer ptr);

void draw_score(GtkWidget *widget, gpointer ptr);

char *count_score();

void test_func(GtkWidget *widget, gpointer ptr);