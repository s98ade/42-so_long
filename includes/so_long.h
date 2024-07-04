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
#include<stdio.h>

# define BLOCK 50

# define TEXTURE_COLLECTABLE "./textures/collectable.png"
# define TEXTURE_PLAYER "./textures/player.png"
# define TEXTURE_WALL "./textures/wall.png"
# define TEXTURE_FLOOR "./textures/space.png"
# define TEXTURE_EXIT "./textures/exit.png"

typedef enum e_move
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} t_move;

typedef struct s_objects
{
    mlx_texture_t   *tex_floor;
    mlx_texture_t   *tex_wall;
    mlx_texture_t   *tex_coin;
    mlx_texture_t   *tex_exit;
    mlx_texture_t   *tex_player;
    mlx_image_t     *img_floor;
    mlx_image_t     *img_wall;
    mlx_image_t     *img_coin;
    mlx_image_t     *img_exit;
    mlx_image_t     *img_player;
} t_objects;

typedef struct s_count
{
    int p;
    int c;
    int e;
} t_count;

typedef struct s_map
{
    t_count     *count;
    int         collected;
    int         map_width;
    int         map_height;
    int         start_x;
    int         start_y;
    mlx_t       *window;
    char        **map;
    t_objects   *imgs;
} t_map;

/* utils */
bool ber_file(const char *str);
int open_file(const char *file);
void free_map(char **map);
void print_steps(void);

/* init_map */
t_map init_data(char *file);
int get_map_depth(const char *file);
int get_map_len(const char *file);
void check_file(const char *file);
void init_map(char *file, t_map *data);

/* map_validation */
void validate_map_sides(t_map *data);
void validate_map_borders(t_map *data);
void validate_map(t_map *data);
void check_items(t_map *data);

/* move_validation */
bool is_wall(t_map *data, t_move move);
void is_exit(t_map *data);
void is_collectable(t_map *data);

/* path_validation */
void validate_path(t_map data);
void flood_fill(char **map, t_map cur, int x, int y);
void is_valid_path(char **map);
void restore_map(char **map);

/* init_game */
void init_texture(t_objects *texture, t_map *data);
void init_images(t_objects *image, mlx_t *window, t_map *data);
mlx_t *init_window(const t_map *data);
void draw_map(t_map *data, mlx_t *window);
void key_hook(mlx_key_data_t keydata, void *params);

/* error_handling */
void file_error(int nbr);
void map_error(int nbr, char *line);
void error_mlx(char **map);
void init_error(int nbr);

#endif