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


typedef enum e_object
{
    PLAYER,
    COLLECTABLE,
    EXIT,
    SPACE,
    OBSTACLE
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
    int         map_width;
    int         map_hight;
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
t_map *read_map(const char *map);
int get_map_depth(const char *file);
int get_map_len(const char *file);
void check_file(const char *file);

/* draw_map */
mlx_t *init_window(const t_map *data);

#endif