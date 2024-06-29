/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:05:28 by sade              #+#    #+#             */
/*   Updated: 2024/06/29 15:24:50 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t *get_image(mlx_t *window, const t_object obj)
{
    mlx_image_t *image;
    mlx_texture_t   *texture;

    texture = mlx_load_png(get_png_path(obj));
    image = mlx_texture_to_image(window, texture);
    mlx_delete_texture(texture);
    if(!image)
        map_error(7, NULL);
    return(image);
}

void draw_map(t_map *data, mlx_t *window)
{
    int y;
    int x;
    t_object obj;

    y = 0;
    while(data->map[y])
    {
        x = 0;
        while(data->map[y][x])
        {
            obj = data->objects[x];
            if(data->map[y][x] == '0')
            {
                mlx_image_to_window(window, get_image(window, obj), x * BLOCK, y * BLOCK); 
                printf("floor\n");
            } 
            else if(data->map[y][x] == '1')
            {
                mlx_image_to_window(window, get_image(window, obj), x * BLOCK, y * BLOCK);
                printf("wall\n");
            }
            else if(data->map[y][x] == 'C')
            {
                mlx_image_to_window(window, get_image(window, obj), x * BLOCK, y * BLOCK);
                printf("coin\n");
            }
            else if(data->map[y][x] == 'E')
            {
                mlx_image_to_window(window, get_image(window, obj), x * BLOCK, y * BLOCK);
                printf("exit\n");
            }
            else if(data->map[y][x] == 'P')
            {
                mlx_image_to_window(window, get_image(window, obj), x * BLOCK, y * BLOCK);
                data->start_y = y;
                data->start_x = x;
                printf("player\n");
            }
            x++;
        }
        y++;
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