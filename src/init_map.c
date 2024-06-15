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

void check_file(const char *file)
{
    int fd;
    char *read_line;

    fd = open_file(file);
    read_line = get_next_line(fd);
    if(read_line == NULL)
    {
        ft_putstr_fd("Error\nMap reading failed!", 2);
        exit(1);
    }
    while(read_line)
    {
        free(read_line);
        read_line = get_next_line(fd);
        if(read_line == NULL)
            break;
    }
    close(fd);
}

int get_map_len(const char *file)
{
    int len;
    int fd;
    char c;

    len = 0;
    fd = open_file(file);
    while(read(fd, &c, 1) > 0)
    {
        if(c == '\n')
            break;
        len++;
    }
    close(fd);
    return(len);
}

int get_map_depth(const char *file)
{
    int rows;
    int fd;
    char c;

    rows = 0;
    fd = open_file(file);
    while(read(fd, &c, 1) > 0)
    {
        if(c == '\n')
            rows++;
    }
    close(fd);
    return(rows);
}

t_map *read_map(const char *file)
{
    t_map *data;

    check_file(file);
    data->map_width = get_map_len(file);
    data->map_hight = get_map_depth(file);
    if(data->map_width == 0 || data->map_hight == 0)
    {
        ft_putstr_fd("Error\n File is empty!\n", 2);
        exit(1);
    }
    data->objects = ((t_object *)malloc(sizeof(t_object) * (data->map_width * data->map_hight)));
    if(!data->objects)
    {
        ft_putstr_fd("Error\n Memory allocation failed!\n", 2);
        exit(1);
    }
}

