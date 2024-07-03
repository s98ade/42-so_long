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
    if(rows > 0 && c != '\n')
        rows++;
    return(rows);
}

void init_map(char *file, t_map *data)
{
    int i;
    int fd;
    char *line;

    fd = open_file(file);
    line = get_next_line(fd);

    data->map = (char **)malloc(sizeof(char *) * (data->map_height + 1));
    i = 0;
    while(line)
    {
        data->map[i] = line;
        line = get_next_line(fd);
        i++;
    }
    data->map[i] = '\0';
    free(line);
    line = NULL;
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
    data.imgs = malloc(sizeof(t_objects));
    init_map(file, &data);
    validate_map(&data);
    return(data);
}
