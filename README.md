# My_Sokoban 📦

Sokoban, which means "warehouse keeper" in Japanese, is a classic transport puzzle game where the player's objective is to push boxes or crates onto designated storage locations within a warehouse. This implementation of Sokoban is designed to run in terminal mode using the ncurses library.

## Rules

- The game is played on a board of squares, where each square is either a floor or a wall.
- Some floor squares contain boxes, and some floor squares are marked as storage locations.
- The player (represented by 'P') can move horizontally or vertically onto empty squares (never through walls or boxes).
- The player can push boxes ('X') by moving into them, but boxes cannot be pulled.
- Boxes may not be pushed into other boxes or walls.
- The puzzle is solved when all boxes are at storage locations.

## How to Create Your Own Map

You can create your own custom maps for the Sokoban game. Simply follow these guidelines:

1. Open a text editor.
2. Create a grid of characters representing the Sokoban game board.
   - Use `#` for walls.
   - Use `P` for the player.
   - Use `X` for boxes.
   - Use `O` for storage locations.
   - Use spaces for empty floor squares.
3. Save your map file with a descriptive name and a `.map` extension.

Here's an example of a custom map file:

```
############
# O        #
# P ####   #
#          #
#######    #
# O        #
####       #
#   XX     #
#   #      #
############
```
## Controls
Use the arrow keys (LEFT, RIGHT, UP, DOWN) to move the player character ('P') on the game board.

  - UP_ARROW    - Move UP
  - DOWN_ARROW  - Move DOWN
  - LEFT_ARROW  - Move LEFT
  - RIGHT_ARROW - Move RIGHT

Press the space bar to reset the game if needed.

# How to run

## Installation Ncurses

### Linux

#### Debian-based systems (such as Ubuntu)
```
sudo apt-get update
sudo apt-get install libncurses-dev
```
####  Red Hat-based systems (such as Fedora)
```
sudo dnf install ncurses-devel
```
## Compiled Program

```
make
./my_sokoban map
```


## Grade

I received a score of 100% on this project.

## Authors
Thank you for checking out this project! If you have any questions or would like to collaborate, feel free to contact me.

[Nicolas Dumetz](mailto:nicolasdumetzpro@gmail.com)
