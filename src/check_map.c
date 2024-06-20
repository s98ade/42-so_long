/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:04:39 by sade              #+#    #+#             */
/*   Updated: 2024/06/20 14:06:36 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void validate_map_borders(t_map *data)
{
    int i;
    
    i = 0;
    while(i < data->map_width)
    {
        if(data->objects[i] != '1')
        {
            ft_putstr_fd("Error\nInvalid borders!\n", 2);
            exit(1);
        }
        i++;
    }
    i = (data->map_width * data->map_hight) - data->map_width;
    while(i < (data->map_width * data->map_hight))
    {
        if(data->objects[i] != '1')
        {
            ft_putstr_fd("Error\nInvalid borders!\n", 2);
            exit(1);
        }
        i++;
    }
}

void validate_map_sides(t_map *data)
{
    int i;
    int start;
    int end;

    i = 0;
    while(i < data->map_hight)
    {
        start = i * data->map_width;
        end = start + data->map_width - 1;
        if(data->objects[start] != '1')
        {
            ft_putstr_fd("Error\nInvalid borders!\n", 2);
            exit(1);
        }
        if(data->objects[end] != '1')
        {
            ft_putstr_fd("Error\nInvalid borders!\n", 2);
            exit(1);
        }
        i++;
    }
}

int count_objects(t_map *data, t_object obj)
{
    int count;
    int i;

    i = 0;
    count = 0;
    while(i < (data->map_width * data->map_hight))
    {
        if(data->objects[i] == obj)
            count++;
        i++;
    }
    return(count);
}

void validate_map(t_map *data)
{
    validate_map_borders(data);
    validate_map(data);
    //
    if(count_objects(data, PLAYER) != 1 || count_objects(data, EXIT) != 1 || count_objects(data, COLLECTABLE) == 0)
    {
        ft_putstr_fd("Error\n Map invalid!", 2);
        //free stuff
        exit(1);
    }
}