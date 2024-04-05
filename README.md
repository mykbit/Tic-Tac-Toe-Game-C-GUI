# Tic Tac Toe with GUI
This is a Tic Tac Toe game written in C with GUI using GTK+3. The game offers 3 game modes: Player vs Player, Player vs Computer and Player vs Computer (Impossible Mode). The game is played on a 3x3 board. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is the winner. GTK3 library provides a clear graphical interface and allows to play the game with a mouse.

## Game Modes
### Player vs Player
In this mode, two players play against each other. The first player is X and the second player is O. The players take turns placing their marks on the board until one of them wins or the board is full.

### Player vs Computer
In this mode, the player plays against the computer. The player is X and the computer is O. The player can choose who starts the game. The player and computer take turns placing their marks on the board following the same rules as in the Player vs Player mode. It is worth noting that the computer is using a simplified version of the minimax algorithm to determine the best move, which allows for faulty moves.

### Player vs Computer (Impossible Mode)
This mode is identical to the Player vs Computer mode, except that the computer is using a full implementation of the minimax algorithm to determine the best move. The computer will never lose in this mode. Don't believe me? Try it yourself!

## Setup
```
brew install gtk+3 && brew install pkg-config
```
## Build and Interact

1. Navigate to the project directory:
```
cd path/to/Tic-Tac-Toe-Game-C-GUI
```

2. Build the game:
```
make all
```

3. Run the game:
```
./build/tic-tac-toe
```

4. Choose the game mode.

5. Open the game window and play!


## Comments
You can find comments to the code in .h files.
## Gameplay
<p align="center">
    <img alt="Gameplay1" src="https://github.com/mykbit/Tic-Tac-Toe-Game-C-GUI/assets/96201443/bee161e5-e5ae-4ff4-9e32-9d161f665421">
    <img alt="Gameplay2" src="https://github.com/mykbit/Tic-Tac-Toe-Game-C-GUI/assets/96201443/172af58a-df11-47ef-873f-a1a918e6b8dd">
</p>
