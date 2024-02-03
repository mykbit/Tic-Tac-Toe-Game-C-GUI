#include <gtk/gtk.h>
#include "button_hashtable.h"

#define MAX_LENGTH 256
#define DEFAULT_X 0
#define DEFAULT_Y 0
#define DEFAULT_W 1000
#define DEFAULT_H 600

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