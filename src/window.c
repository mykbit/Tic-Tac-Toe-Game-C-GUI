#include "window.h"
#include "game_logic.h"
#include "variables.h"

int window_x = DEFAULT_X;
int window_y = DEFAULT_Y;
int width_x = DEFAULT_W;
int height_y = DEFAULT_H;
char current_symbol = 'X';
int X = 0;
int O = 0;
char matrix[3][3];

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

HashTable *table;

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


void create_game_window() {
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_NONE);
    gtk_window_move(GTK_WINDOW(window), window_x, window_y+28);
    gtk_window_resize(GTK_WINDOW(window), width_x, height_y);
    gtk_window_set_title(GTK_WINDOW(window), "Tic Tac Toe");
    window_handler_id = g_signal_connect(window, "delete_event", G_CALLBACK(quit_app), NULL);

    table = hash_table_create();

    current_turn_string = "Player 1's Turn";
    start_game_string = "Game Start!";

    exit_button = gtk_button_new_with_label("Exit");
    exit_button_handler_id = g_signal_connect(exit_button, "clicked", G_CALLBACK(quit_app), NULL);

    restart_btn = gtk_button_new_with_label("Restart");
    restart_button_handler_id = g_signal_connect(restart_btn, "clicked", G_CALLBACK(restart_game), NULL);
    gtk_widget_set_sensitive(restart_btn, FALSE);

    score_lbl = gtk_label_new(NULL);
    draw_score(score_lbl, X, O);

    turn_lbl = gtk_label_new(NULL);
    gtk_label_set_text(GTK_LABEL(turn_lbl), start_game_string);

    // create a grid to hold the score and exit button
    game_grid = gtk_grid_new();

    // create buttons 3 by 3
    btn11 = gtk_button_new_with_label("\u00B7");
    btn12 = gtk_button_new_with_label("\u00B7");
    btn13 = gtk_button_new_with_label("\u00B7");
    btn21 = gtk_button_new_with_label("\u00B7");
    btn22 = gtk_button_new_with_label("\u00B7");
    btn23 = gtk_button_new_with_label("\u00B7");
    btn31 = gtk_button_new_with_label("\u00B7");
    btn32 = gtk_button_new_with_label("\u00B7");
    btn33 = gtk_button_new_with_label("\u00B7");

    // create signal handlers for the buttons
    btn11_handler_id = g_signal_connect(btn11, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn11), "id", "00");
    hash_table_insert(table, "00", btn11);

    btn12_handler_id = g_signal_connect(btn12, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn12), "id", "01");
    hash_table_insert(table, "01", btn12);

    btn13_handler_id = g_signal_connect(btn13, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn13), "id", "02");
    hash_table_insert(table, "02", btn13);

    btn21_handler_id = g_signal_connect(btn21, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn21), "id", "10");
    hash_table_insert(table, "10", btn21);

    btn22_handler_id = g_signal_connect(btn22, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn22), "id", "11");
    hash_table_insert(table, "11", btn22);

    btn23_handler_id = g_signal_connect(btn23, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn23), "id", "12");
    hash_table_insert(table, "12", btn23);

    btn31_handler_id = g_signal_connect(btn31, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn31), "id", "20");
    hash_table_insert(table, "20", btn31);

    btn32_handler_id = g_signal_connect(btn32, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn32), "id", "21");
    hash_table_insert(table, "21", btn32);

    btn33_handler_id = g_signal_connect(btn33, "clicked", G_CALLBACK(button_click_callback), turn_lbl);
    g_object_set_data(G_OBJECT(btn33), "id", "22");
    hash_table_insert(table, "22", btn33);

    // make widgets expand to fill the grid
    gtk_widget_set_hexpand(btn11, TRUE);
    gtk_widget_set_vexpand(btn11, TRUE);
    gtk_widget_set_hexpand(btn12, TRUE);
    gtk_widget_set_vexpand(btn12, TRUE);
    gtk_widget_set_hexpand(btn13, TRUE);
    gtk_widget_set_vexpand(btn13, TRUE);
    gtk_widget_set_hexpand(btn21, TRUE);
    gtk_widget_set_vexpand(btn21, TRUE);
    gtk_widget_set_hexpand(btn22, TRUE);
    gtk_widget_set_vexpand(btn22, TRUE);
    gtk_widget_set_hexpand(btn23, TRUE);
    gtk_widget_set_vexpand(btn23, TRUE);
    gtk_widget_set_hexpand(btn31, TRUE);
    gtk_widget_set_vexpand(btn31, TRUE);
    gtk_widget_set_hexpand(btn32, TRUE);
    gtk_widget_set_vexpand(btn32, TRUE);
    gtk_widget_set_hexpand(btn33, TRUE);
    gtk_widget_set_vexpand(btn33, TRUE);
    
    // add the buttons to the grid
    gtk_grid_attach(GTK_GRID(game_grid), btn11, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn12, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn13, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn21, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn22, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn23, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn31, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn32, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(game_grid), btn33, 2, 2, 1, 1);

    // create a grid to hold the button and label
    main_grid = gtk_grid_new();

    // make the widgets expand to fill the grid
    gtk_widget_set_hexpand(exit_button, TRUE);
    gtk_widget_set_vexpand(exit_button, TRUE);
    gtk_widget_set_hexpand(score_lbl, TRUE);
    gtk_widget_set_vexpand(score_lbl, TRUE);
    gtk_widget_set_hexpand(turn_lbl, TRUE);
    gtk_widget_set_vexpand(turn_lbl, TRUE);
    gtk_widget_set_hexpand(restart_btn, TRUE);
    gtk_widget_set_vexpand(restart_btn, TRUE);

    if (sel_mode >= 2) {
        add_buttons_for_pve();
    }
    
    gtk_grid_attach(GTK_GRID(main_grid), turn_lbl,    0, 0, 6, 3);
    gtk_grid_attach(GTK_GRID(main_grid), game_grid,   0, 3, 3, 30);
    gtk_grid_attach(GTK_GRID(main_grid), score_lbl,   3, 3, 3, 15);
    gtk_grid_attach(GTK_GRID(main_grid), restart_btn, 3, 21, 3, 6);
    gtk_grid_attach(GTK_GRID(main_grid), exit_button, 3, 27, 3, 6);  

    gtk_container_add(GTK_CONTAINER(window), main_grid);
    gtk_widget_show_all(window);
    if (sel_mode == 1) {
        g_timeout_add_seconds(3, game_start_text, turn_lbl);
    }
}

void open_window() {
    create_game_window();
    gtk_main();
}

void quit_app(GtkWidget *widget, gpointer ptr) {
    gtk_main_quit();
}

void restart_game(GtkWidget *widget, gpointer ptr) {
    current_symbol = 'X';
    game_finished = FALSE;
    player1_first_move = FALSE;
    cpu_first_move = FALSE;
    clean_matrix();
    hash_table_destroy(table);
    gtk_window_get_position(GTK_WINDOW(window), &window_x, &window_y);
    gtk_window_get_size(GTK_WINDOW(window), &width_x, &height_y);
    gtk_widget_destroy(window);
    gtk_main_quit();
    open_window();
}

void add_buttons_for_pve() {
    player1_btn = gtk_button_new_with_label("First move\n  Player 1");
    g_object_set_data(G_OBJECT(player1_btn), "id", "1");
    player1_btn_handler_id = g_signal_connect(player1_btn, "clicked", G_CALLBACK(first_move_btn_callback), turn_lbl);
    gtk_widget_set_hexpand(player1_btn, TRUE);
    gtk_widget_set_vexpand(player1_btn, TRUE);

    cpu_btn = gtk_button_new_with_label("First move\n     CPU");
    g_object_set_data(G_OBJECT(cpu_btn), "id", "2");
    cpu_btn_handler_id = g_signal_connect(cpu_btn, "clicked", G_CALLBACK(first_move_btn_callback), turn_lbl);
    gtk_widget_set_hexpand(cpu_btn, TRUE);
    gtk_widget_set_vexpand(cpu_btn, TRUE);

    gtk_grid_attach(GTK_GRID(main_grid), player1_btn, 3, 18, 1, 1);
    gtk_grid_attach(GTK_GRID(main_grid), cpu_btn, 4, 18, 1, 1);
    gtk_widget_set_sensitive(game_grid, FALSE);
}