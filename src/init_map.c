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
        map_error(1, NULL);
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

void init_map(char *file, t_map *data)
{
    int i;
    int fd;

    i = -1;
    fd = open_file(file);
    data->map = malloc((data->map_height + 1) * sizeof(char *));
    // error-handling
    while(i++ < data->map_height - 1)
    {
        data->map[i] = get_next_line(fd);
        // if((int)ft_strlen(data->map[i]) != (data->map_width + 1))
        // {
        //     //error-handling
        // }
    }
    data->map[i] = get_next_line(fd);
    data->map[i++] = ft_strdup("\0");
    close(fd);
}

t_map init_data(char *file)
{
    t_map data;

    data.map_width = get_map_len(file);
    data.map_height = get_map_depth(file);
    if(data.map_width == 0 || data.map_height == 0)
        file_error(3);
    data.map = NULL;
    data.objects = (t_object *)malloc(sizeof(t_object) * data.map_width * data.map_height);
    if(!data.objects)
        file_error(1);
    read_map(file, &data);
    init_map(file, &data);
    return(data);
}
