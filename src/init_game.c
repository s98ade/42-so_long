/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:05:28 by sade              #+#    #+#             */
/*   Updated: 2024/06/26 18:33:31 by sofia            ###   ########.fr       */
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

void draw_map(t_map *data)
{
    draw_floor(data);
    draw_walls(data);
    draw_collectables(data);
    draw_exit(data);
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