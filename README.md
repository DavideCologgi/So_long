# So Long

## Game Description

So Long is a basic 2D game where the player controls Eden's snake, which needs to collect all the apples scattered around the level while being cautious of enemy eagles.

## General Instructions

- The game is built using the graphical library MiniLibX.
- A Makefile is provided to compile all the source code.
- The game requires a map description file with the ".ber" extension as a valid parameter.

## Map Rules

- The map must be rectangular (not squared).
- The map should contain the following elements: one player, one exit, at least one collectible item, and one enemy.
- The map must be enclosed by walls.

## Gameplay Rules

- The player's objective is to collect all collectibles on the map before reaching the exit.
- The player can move in four directions: up, left, down, and right.
- Player movements are controlled using the W, A, S, and D keys.
- The player cannot move through walls.
- After each move, a counter is displayed on the screen and in the shell.
- If the player comes into contact with an enemy, the game closes, and the player loses.
- The game can be closed by pressing the ESC key or by clicking the cross on the window's frame.

## Launching the Game

To launch the game, follow these simple steps:

1. Navigate to the "so_long" folder.
2. Run the following command: `make` to compile the game.
3. Start the game by running the command: `./so_long "map-name.ber"` where "map-name.ber" is the name of the map file you want to play.

Enjoy the game!
