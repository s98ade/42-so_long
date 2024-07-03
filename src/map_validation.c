/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:04:39 by sade              #+#    #+#             */
/*   Updated: 2024/07/03 17:34:53 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void validate_map_borders(t_map *data)
{
    int i;
    
    i = 0;
    while(i < data->map_width)
    {
        if(data->map[0][i] != '1')
            map_error(5, NULL);
        i++;
    }
    i = 0;
    while(i < data->map_width)
    {
        if(data->map[data->map_height - 1][i] != '1')
            map_error(5, NULL);
        i++;
    }
}

void validate_map_sides(t_map *data)
{
    int i;

    i = 0;
    while(i < data->map_height)
    {
        if(data->map[i][0] != '1')
            map_error(5, NULL);
        if(data->map[i][data->map_width - 1] != '1')
            map_error(5, NULL);
        i++;
    }
}

void check_items(t_map *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(data->map[j])
    {
        i = 0;
        while(data->map[j][i])
        {
            if(data->map[j][i] == 'P')
                data->count->p += 1;
            else if(data->map[j][i] == 'E')
                data->count->e += 1;
            else if(data->map[j][i] == 'C')
                data->count->c += 1;
            i++;
        }
        j++;
    }
    if(data->count->c == 0 || data->count->p == 0 || data->count->e == 0 || data->count->p > 1)
        map_error(6, NULL);
}

void validate_map(t_map *data)
{
    data->count->c = 0;
    data->count->e = 0;
    data->count->p = 0;
    
    validate_map_borders(data);
    validate_map_sides(data);
    check_items(data);  
}
