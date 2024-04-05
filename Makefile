build:
	gcc -o build/tic-tac-toe src/main.c src/start_game.c src/window.c src/game_logic.c src/button_hashtable.c `pkg-config --cflags --libs gtk+-3.0`

run:
	./build/tic-tac-toe

all:
	make build && make run