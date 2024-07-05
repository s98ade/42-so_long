/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:09:49 by sofia             #+#    #+#             */
/*   Updated: 2024/07/05 10:29:36 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void init_texture(t_objects *texture, t_map *data)
{
    texture->tex_floor = mlx_load_png(TEXTURE_FLOOR);
    if(!texture->tex_floor)
        error_mlx(data->map);
    texture->tex_wall = mlx_load_png(TEXTURE_WALL);
    if(!texture->tex_wall)
        error_mlx(data->map);
    texture->tex_coin = mlx_load_png(TEXTURE_COLLECTABLE);
    if(!texture->tex_coin)
        error_mlx(data->map);
    texture->tex_exit = mlx_load_png(TEXTURE_EXIT);
    if(!texture->tex_exit)
        error_mlx(data->map);
    texture->tex_player = mlx_load_png(TEXTURE_PLAYER);
    if(!texture->tex_player)
        error_mlx(data->map);
}

void init_images(t_objects *image, mlx_t *window, t_map *data)
{
    image->img_floor = mlx_texture_to_image(window, image->tex_floor);
    if(!image->img_floor)
        error_mlx(data->map);
    mlx_delete_texture(image->tex_floor);
    image->img_wall = mlx_texture_to_image(window, image->tex_wall);
    if(!image->img_wall)
        error_mlx(data->map);
    mlx_delete_texture(image->tex_wall);
    image->img_coin = mlx_texture_to_image(window, image->tex_coin);
    if(!image->img_coin)
        error_mlx(data->map);
    mlx_delete_texture(image->tex_coin);
    image->img_exit = mlx_texture_to_image(window, image->tex_exit);
    if(!image->img_exit)
        error_mlx(data->map);
    mlx_delete_texture(image->tex_exit);
    image->img_player = mlx_texture_to_image(window, image->tex_player);
    if(!image->img_player)
        error_mlx(data->map);
    mlx_delete_texture(image->tex_player);
}

void draw_map(t_map *data, mlx_t *window)
{
    // ERROR HANDLING MISSING
    int i;
    int j;

    i = 0;
    while(i < data->map_height)
    {
        j = 0;
        while(j < data->map_width)
        {
            if(data->map[i][j] == '1')
                mlx_image_to_window(window, data->imgs->img_wall, j * BLOCK, i * BLOCK);
            else if(data->map[i][j] == '0')
                mlx_image_to_window(window, data->imgs->img_floor, j * BLOCK, i * BLOCK);
            else if(data->map[i][j] == 'C')
                mlx_image_to_window(window, data->imgs->img_coin, j * BLOCK, i * BLOCK);
            else if(data->map[i][j] == 'E')
                mlx_image_to_window(window, data->imgs->img_exit, j * BLOCK, i * BLOCK);
            else if(data->map[i][j] == 'P')
                mlx_image_to_window(window, data->imgs->img_player, j * BLOCK, i * BLOCK);
            j++;
        }
        i++;
    }
}

mlx_t *init_window(const t_map *data)
{
    mlx_t *window;

    window = mlx_init(BLOCK * data->map_width, BLOCK * data->map_height, "so_long", true);
    if(!window)
        init_error(2);
    return(window);
}

void key_hook(mlx_key_data_t keydata, void *params)
{
    t_map *data;

    data = params;
    if(keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(data->window);
    if(data->imgs->img_player->instances[0].enabled == true)
    {
        if(keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
            if(!is_wall(data, UP))
                data->imgs->img_player->instances[0].y -= BLOCK;
        if(keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
            if(!is_wall(data, DOWN))
                data->imgs->img_player->instances[0].y += BLOCK;
        if(keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
            if(!is_wall(data, LEFT))
                data->imgs->img_player->instances[0].x -= BLOCK;
        if(keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
            if(!is_wall(data, RIGHT))
                data->imgs->img_player->instances[0].x += BLOCK;
        is_collectable(data);
        is_exit(data);
    }
}
