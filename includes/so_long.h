/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:59:11 by sade              #+#    #+#             */
/*   Updated: 2024/03/01 20:59:11 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../Libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

#include <fcntl.h>
#include <stdbool.h>

# define BLOCK 50

# define TEXTURE_COLLECTABLE "collectable.png"
# define TEXTURE_PLAYER "player.png"
# define TEXTURE_WALL "wall.png"
# define TEXTURE_FLOOR "space.png"
# define TEXTURE_EXIT "exit.png"

typedef enum e_object
{
    PLAYER,
    COLLECTABLE,
    EXIT,
    FLOOR,
    WALL
} t_object;

typedef enum e_move
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} t_move;

typedef struct s_map
{
    int         collectables;
    int         collected;
    int         map_width;
    int         map_height;
    int         start_x;
    int         start_y;
    mlx_t       *window;
    char        **map;
    t_object    *objects;
} t_map;

/* utils */
bool ber_file(const char *str);
int open_file(const char *file);
int count_objects(t_map *data, t_object obj);
void *get_png_path(const t_object obj);

/* init_map */
t_map init_data(char *file);
int get_map_depth(const char *file);
int get_map_len(const char *file);
void check_file(const char *file);

/* check_map */
void validate_map_sides(t_map *data);
void validate_map_borders(t_map *data);
void validate_map(t_map *data);

/* convert */
void read_map(const char *file, t_map *data);
void read_line(int fd, int height, t_map *data);
t_object get_objects(const char obj);

/* init_game */
mlx_t *init_window(const t_map *data);
mlx_image_t *get_image(mlx_t *window, const t_object obj);
void draw_map(t_map *data, mlx_t *window);

/* draw_map */
void draw_floor(t_map *data, mlx_t *window);
void draw_walls(t_map *data, mlx_t *window);
void draw_collectables(t_map *data, mlx_t *window);
void draw_exit(t_map *data, mlx_t *window);

/* error_handling */
void file_error(int nbr);
void map_error(int nbr, char *line);

#endif