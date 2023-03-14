You have to create a basic 2D game in which a dolphin escapes Earth after eating some fish.
Instead of a dolphin, fish, and the Earth, you can use any character, any collectible and any place you want.

- General instructions:
- You have to use the graphical library MiniLibX;
- The program must use a Makefile to compile all of your sources and it must not relink;
- The program must take as a valid parameter a map description file with the ".ber" extension.

- Map rules:
- Map must be rectangular (not squared);
- Map must contain one player, one exit and at least one collectible and enemy;
- Map must be surrounded by walls.

- Gameplay rules:
- Player must collect every collectibles on the map before going to the exit;
- Player must be able to move in four directions: up, left, down and right;
- Player's movements must be handled with W, A, S, and D keys;
- Player cannot move into walls;
- After each move, a counter must be displayed on screen and in the shell;
- If the player "touch" an enemy, the game closes and you lose;
- Game must close if either ESC key is pressed or by clicking on the cross on the window’s frame.
