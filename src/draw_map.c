/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:26:52 by sofia             #+#    #+#             */
/*   Updated: 2024/06/28 15:54:25 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// void draw_floor(t_map *data, mlx_t *window, int *y, int *x)
// {
//     mlx_image_to_window(window, get_image(window, ), (*x) * BLOCK, (*y) * BLOCK);  
// }

// void draw_walls(t_map *data, mlx_t *window, int *y, int *x)
// {
//     (void)*data;
//     mlx_image_to_window(window, get_image(window, WALL), (*x) * BLOCK, (*y) * BLOCK); 
// }

// void draw_collectables(t_map *data, mlx_t *window, int *y, int *x)
// {
//     (void)*data;
//     mlx_image_to_window(window, get_image(window, COLLECTABLE), (*x) * BLOCK, (*y) * BLOCK); 
// }

// void draw_exit(t_map *data, mlx_t *window, int *y, int *x)
// {
//     (void)*data;
//     mlx_image_to_window(window, get_image(window, EXIT), (*x) * BLOCK, (*y) * BLOCK); 
// }

// void draw_player(t_map *data, mlx_t *window, int *y, int *x)
// {
//     mlx_image_to_window(window, get_image(window, PLAYER), (*x) * BLOCK, (*y) * BLOCK);
//     data->start_y = *y;
//     data->start_x = *x; 
// }