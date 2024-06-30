/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:05:28 by sade              #+#    #+#             */
/*   Updated: 2024/06/30 10:44:00 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_texture(t_objects *texture)
{
    // ERROR HANDLING MISSING
    texture->tex_floor = mlx_load_png(TEXTURE_FLOOR);
    texture->tex_wall = mlx_load_png(TEXTURE_WALL);
    texture->tex_coin = mlx_load_png(TEXTURE_COLLECTABLE);
    texture->tex_exit = mlx_load_png(TEXTURE_EXIT);
    texture->tex_player = mlx_load_png(TEXTURE_PLAYER);
}

void init_images(t_objects *image, mlx_t *window)
{
    // ERROR HANDLING MISSING
    image->img_floor = mlx_texture_to_image(window, image->tex_floor);
    // if(!image->img_floor)
    //     mlx_delete_texture(image->img_floor);
    image->img_wall = mlx_texture_to_image(window, image->tex_wall);
    // if(!image->img_wall)
    //     mlx_delete_texture(image->img_wall);
    image->img_coin = mlx_texture_to_image(window, image->tex_coin);
    // if(!image->img_coin)
    //     mlx_delete_texture(image->img_coin);
    image->img_exit = mlx_texture_to_image(window, image->tex_exit);
    // if(!image->img_exit)
    //     mlx_delete_texture(image->img_exit);
    image->img_player = mlx_texture_to_image(window, image->tex_player);
    // if(!image->img_player)
    //     mlx_delete_texture(image->img_player);
}

void draw_map(t_map *data, mlx_t *window)
{
    // ERROR HANDLING MISSING
    int i;
    int j;

    i = 0;
    while(data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if(data->map[i][j] == '1')
                mlx_image_to_window(window, data->imgs->img_wall, i * BLOCK, j * BLOCK);
            else if(data->map[i][j] == '0')
                mlx_image_to_window(window, data->imgs->img_floor, i * BLOCK, j * BLOCK);
            else if(data->map[i][j] == 'C')
                mlx_image_to_window(window, data->imgs->img_coin, i * BLOCK, j * BLOCK);
            else if(data->map[i][j] == 'E')
                mlx_image_to_window(window, data->imgs->img_exit, i * BLOCK, j * BLOCK);
            else if(data->map[i][j] == 'P')
            {
                mlx_image_to_window(window, data->imgs->img_player, i * BLOCK, j * BLOCK);
                data->start_y = i;
                data->start_x = j;
            }
            j++;
        }
        i++;
    }
}

// void key_hook()

mlx_t *init_window(const t_map *data)
{
    mlx_t *window;

    window = mlx_init(BLOCK * data->map_width, BLOCK * data->map_height, "so_long", true);
    if(!window)
        map_error(2, NULL);
    return(window);
}