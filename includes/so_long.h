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

/* init_map */
t_map init_data(char *file);
int get_map_depth(const char *file);
int get_map_len(const char *file);
void check_file(const char *file);

/* check_map */
void validate_map_sides(t_map *data);
void validate_map_borders(t_map *data);
void validate_map(t_map *data);
int count_objects(t_map *data, t_object obj);

/* convert */
void read_map(const char *file, t_map *data);
void read_line(int fd, int height, t_map *data);
t_object get_objects(const char obj);

/* draw_map */
mlx_t *init_window(const t_map *data);

/* error_handling */
void file_error(int nbr);
void map_error(int nbr, char *line);

#endif