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
    int fd;
    int i;

    i = -1;
    check_file(file);
    fd = open_file(file);
    data->map_width = get_map_len(file);
    data->map_hight = get_map_depth(file);
    if(data->map_width == 0 || data->map_hight == 0)
    {
        ft_putstr_fd("Error\nFile is empty!\n", 2);
        free(data);
        exit(1);
    }
    data->map = malloc((data->map_hight + 1) * sizeof(char *));
    if(data->map == NULL)
    {
        ft_putstr_fd("Error\nMemory allocation failed!\n", 2);
        free(data); //don´t know whehter correct
        exit(1);
    }
    while(++i < data->map_hight - 1)
    {
        data->map[i] = get_next_line(fd);
        if(ft_strlen(data->map[i] != (data->map_width + 1)))
        {
            ft_putstr_fd("Error\nInvalid mpa!\n", 2);
            free(data); //don´t know whether correct
        }
    }
    data->map[i] = get_next_line(fd);
    data->map[i++] = ft_strdup("\0");
    // fill map
    validate_map(data);
    close(fd);
    return(data);
}
