/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:04:39 by sade              #+#    #+#             */
/*   Updated: 2024/06/28 14:50:00 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "so_long.h"

void validate_map_borders(t_map *data)
{
    int i;
    
    i = 0;
    while(i < data->map_width)
    {
        if(data->objects[i] != '1')
            map_error(5, NULL);
        i++;
    }
    i = (data->map_width * data->map_height) - data->map_width;
    while(i < (data->map_width * data->map_height))
    {
        if(data->objects[i] != '1')
            map_error(5, NULL);
        i++;
    }
}

void validate_map_sides(t_map *data)
{
    int i;
    int start;
    int end;

    i = 0;
    while(i < data->map_height)
    {
        start = i * data->map_width;
        end = start + data->map_width - 1;
        if(data->objects[start] != '1')
            map_error(5, NULL);
        if(data->objects[end] != '1')
            map_error(5, NULL);
        i++;
    }
}

void validate_map(t_map *data)
{
    validate_map_borders(data);
    validate_map__sides(data);
    //
    if(count_objects(data, PLAYER) != 1 || count_objects(data, EXIT) != 1 || count_objects(data, COLLECTABLE) == 0)
    {
        ft_putstr_fd("Error\nMap invalid!\ntype: OBJECTS\n", 2);
        free(data->objects);
        exit(1);
    }
} */
