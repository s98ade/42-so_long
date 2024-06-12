/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:50:40 by sade              #+#    #+#             */
/*   Updated: 2024/03/13 18:50:40 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_map_len(const char *file)
{

}

int count_rows(const char *file)
{

}

t_map init_map(const char *file)
{
    t_map *data;

    data->x = get_map_len(file);
    data->y = count_rows(file);
    if(data->x == 0 || data->y == 0)
    {
        ft_putstr_fd("Error\n File is empty!\n", 2);
        exit(1);
    }
    data->objects = ((t_object *)malloc(sizeof(t_object) * (data->x * data->y)));
    if(!data->objects)
    {
        ft_putstr_fd("Error\n Memory allocation failed!\n", 2);
        exit(1);
    }
}

