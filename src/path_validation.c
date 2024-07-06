/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:00:52 by sofia             #+#    #+#             */
/*   Updated: 2024/07/05 13:07:36 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(char **map, t_map *cur, int x, int y)
{
    if(y < 0 || y >= cur->map_height || x < 0 || x >= cur->map_width || map[y][x] == '1')
        return ;
    if(map[y][x] == 'f' || map[y][x] == 'c' || map[y][x] == 'e')
        return ;
    else if(map[y][x] == '0')
        map[y][x] = 'f';
    else if(map[y][x] == 'C')
        map[y][x] = 'c';
    else if(map[y][x] == 'E')
        map[y][x] = 'e';
    flood_fill(map, cur, x - 1, y);
    flood_fill(map, cur, x + 1, y);
    flood_fill(map, cur, x, y - 1);
    flood_fill(map, cur, x, y + 1);
}

void is_valid_path(char **map)
{
    int i;

    i = 0;
    while(map[i] != NULL)
    {
        if(ft_strchr(map[i], 'E') != NULL)
        {
            free_map(map);
            map_error(7, NULL);
        }
        if(ft_strchr(map[i], 'C') != NULL)
        {
            free_map(map);
            map_error(7, NULL);
        }
        i++;    
    }
}

void restore_map(char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i] != NULL)
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'f')
                map[i][j] = '0';
            else if(map[i][j] == 'c')
                map[i][j] = 'C';
            else if(map[i][j] == 'e')
                map[i][j] = 'E';
            j++;
        }
        i++;
    }
}

void validate_path(t_map *data)
{
    flood_fill(data->map, data, data->start_x, data->start_y);
    is_valid_path(data->map);
    restore_map(data->map);
}
