/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:48:05 by sofia             #+#    #+#             */
/*   Updated: 2024/07/06 10:02:20 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_floor(t_map *data, mlx_t *window)
{
    int i;
    int j;

    i = 0;
    while(i < data->map_height)
    {
        j = 0;
        while(j < data->map_width)
        {
            mlx_image_to_window(window, data->imgs->img_floor, j * BLOCK, i * BLOCK);
            j++;
        }
        i++;
    }
}

void draw_walls(t_map *data, mlx_t *window)
{
    int i;
    int j;
    char **tmp_map;

    i = 0;
    tmp_map = data->map;
    while(i < data->map_height)
    {
        j = 0;
        while(j < data->map_width)
        {
            if(tmp_map[i][j] == '1')
                mlx_image_to_window(window, data->imgs->img_wall, j * BLOCK, i * BLOCK);
            j++;
        }
        i++;
    }  
} 

void draw_exit(t_map *data, mlx_t *window)
{
    int i;
    int j;
    char **tmp_map;

    i = 0;
    tmp_map = data->map;
    while(i < data->map_height)
    {
        j = 0;
        while(j < data->map_width)
        {
            if(tmp_map[i][j] == 'E')
                mlx_image_to_window(window, data->imgs->img_exit, j * BLOCK, i * BLOCK);
            j++;
        }
        i++;
    }  
} 

void draw_collectables(t_map *data, mlx_t *window)
{
    int i;
    int j;
    char **tmp_map;

    i = 0;
    tmp_map = data->map;
    while(i < data->map_height)
    {
        j = 0;
        while(j < data->map_width)
        {
            if(tmp_map[i][j] == 'C')
                mlx_image_to_window(window, data->imgs->img_coin, j * BLOCK, i * BLOCK);
            j++;
        }
        i++;
    }  
}

void draw_player(t_map *data, mlx_t *window)
{
    int i;
    int j;
    char **tmp_map;

    i = 0;
    tmp_map = data->map;
    while(i < data->map_height)
    {
        j = 0;
        while(j < data->map_width)
        {
            if(tmp_map[i][j] == 'P')
                mlx_image_to_window(window, data->imgs->img_player, j * BLOCK, i * BLOCK);
            j++;
        }
        i++;
    }  
}
