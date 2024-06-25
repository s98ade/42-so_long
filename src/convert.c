/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:01:32 by sade              #+#    #+#             */
/*   Updated: 2024/06/25 15:53:40 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_line(int fd, int height, t_map *data)
{
    char *line;
    int width;

    line = get_next_line(fd);
    if(!line)
    {
        close(fd);
        map_error(3, NULL);
    }
    width = 0;
    while(line[width] != '\n' && line[width])
    {
        if(width < data->map_width)
            data->objects[data->map_width * height + width] = convert_objects(line[width]);
        width++;
    }
    if(width != data->map_width)
    {
        close(fd);
        map_error(4, line);
    }
    free(line);
}

t_object convert_objects(const char obj)
{
    if(obj == 'C')
        return(COLLECTABLE);
    else if(obj == 'E')
        return(EXIT);    
    else if(obj == '1')
        return(WALL); 
    else if(obj == '0')
        return(FLOOR);
    else if(obj == 'P')
        return(PLAYER);
    else
    {
        ft_putstr_fd("Error\nMap invalid!\ntype: SYMBOLS\n", 2);
        exit(1);
    }  
}

void read_map(const char *file, t_map *data)
{
    int fd;
    int i;

    i = 0;
    fd = open_file(file);
    while(i < data->map_height);
    {
        read_line(fd, i, data);
        i++;
    }
    close(fd);
}

