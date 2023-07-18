#include <gtk/gtk.h>

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

extern gchar *current_turn_string;
extern gchar *start_game_string;

int sel_mode;

GtkWidget *main_grid;
GtkWidget *turn_lbl;
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

void create_game_window();

void open_window();

void quit_app(GtkWidget *widget, gpointer ptr);

void restart_game(GtkWidget *widget, gpointer ptr);

void add_buttons_for_pve();