# 42-so_long

### Table of Contents
- [Introduction](#introduction)
- [Requirements](#Requirements)
- [How to run](#How-to-run)

### Introduction
so_long is a game-project from the ecole 42 curriculum, where a minimal 2D game has to be build, entirely written in C, using the school own library [MLX42](https://github.com/codam-coding-college/MLX42). Objective in the game is to navigate the player through the map, collecting all collectables, before exiting the map. Game assets were retrived from [itch.io](https://itch.io/game-assets/free/tag-sprites).

### Requirements
The program has to fulfill following requirements:
- the player should be able to move in for directions: up, down, left, and right
- for moving the player following keys should be used: `W`, `S`, `A`, `D`
- the player can't walk into walls
- with every move the current number of steps should be displayed in the stdout
- the program must accept a file in `.ber` format to proccess the map
- the map must consist of the following symbols:

| Character | Item |
| ----------- | ----------- |
| 1 | Wall |
| 0 | Floor |
| P | Player |
| C | Coin |
| E | Exit |


### How to run
