/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:05:28 by sade              #+#    #+#             */
/*   Updated: 2024/06/29 19:38:30 by sofia            ###   ########.fr       */
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

void init_objects(t_map *data)
{
    int i;
    
    data->objects[FLOOR] = get_image(data->window, FLOOR);
    data->objects[WALL] = get_image(data->window, WALL);
    data->objects[COLLECTABLE] = get_image(data->window, COLLECTABLE);
    data->objects[EXIT] = get_image(data->window, EXIT);
    data->objects[PLAYER] = get_image(data->window, PLAYER); 
    i = 0;
    while(i < NUM_OBJ)
    {
        if(!data->objects[i])
            map_error(7, NULL);
        i++;
    }
}

void draw_map(t_map *data, mlx_t *window)
{
    int y;
    int x;
    mlx_image_t *obj;

    y = 0;
    while(data->map[y])
    {
        x = 0;
        while(data->map[y][x])
        {
            obj = NULL;
            if(data->map[y][x] == '0')
            {
                obj = data->objects[FLOOR]; 
                printf("floor\n");
            } 
            else if(data->map[y][x] == '1')
            {
                obj = data->objects[WALL];
                printf("wall\n");
            }
            else if(data->map[y][x] == 'C')
            {
                obj = data->objects[COLLECTABLE];
                printf("coin\n");
            }
            else if(data->map[y][x] == 'E')
            {
                obj = data->objects[EXIT];
                printf("exit\n");
            }
            else if(data->map[y][x] == 'P')
            {
                obj = data->objects[PLAYER];
                data->start_y = y;
                data->start_x = x;
                printf("player\n");
            }
            if(obj)
                mlx_image_to_window(window, obj, x * BLOCK, y * BLOCK);
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