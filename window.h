#include <gtk/gtk.h>
#include "button_hashtable.h"

#define MAX_LENGTH 256
#define DEFAULT_X 0
#define DEFAULT_Y 0
#define DEFAULT_W 1000
#define DEFAULT_H 600

extern GtkWidget *window;
extern GtkWidget *exit_button;
extern GtkWidget *score_lbl;
extern GtkWidget *game_grid;
extern GtkWidget *restart_btn;
extern GtkWidget *player1_btn;
extern GtkWidget *cpu_btn;
extern GtkWidget *turn_lbl;

extern gchar *current_turn_string;
extern gchar *start_game_string;

extern HashTable *table;

GtkWidget *main_grid;
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
gulong player1_btn_handler_id;
gulong cpu_btn_handler_id;

char current_symbol;

// Creates the main window by adding all the widgets and setting their properties
void create_game_window();

// Calls the function to create the main window and starts the main loop
void open_window();

// Quits the application
void quit_app(GtkWidget *widget, gpointer ptr);

// Restarts the game by resetting variables and clearing the matrix
void restart_game(GtkWidget *widget, gpointer ptr);

// Adds the buttons for the player vs CPU mode
void add_buttons_for_pve();