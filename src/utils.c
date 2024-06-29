/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:53:52 by sade              #+#    #+#             */
/*   Updated: 2024/06/12 14:53:52 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"so_long.h"

bool ber_file(const char *str)
{
    size_t len;

    len = ft_strlen(str);
    if(ft_strncmp(".ber", str + len - 4, 4) == 0)
        return(true);
    return(false);
}

int open_file(const char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if(fd == -1)
    {
        ft_putstr_fd("Error\nFile couldn't be opened!\n", 2);
        close(fd);
        exit(1);
    }
    return(fd);
}

/* int count_objects(t_map *data, t_object obj)
{
    int count;
    int i;

    i = 0;
    count = 0;
    while(i < (data->map_width * data->map_height))
    {
        if(data->objects[i] == obj)
            count++;
        i++;
    }
    return(count);
} */

const char *get_png_path(const t_object obj)
{
    if(obj == COLLECTABLE)
        return(TEXTURE_COLLECTABLE);
    else if(obj == EXIT)
        return(TEXTURE_EXIT);
    else if(obj == WALL)
        return(TEXTURE_WALL);
    else if(obj == FLOOR)
        return(TEXTURE_FLOOR);
    else if(obj == PLAYER)
        return(TEXTURE_PLAYER);
    else
        return(NULL);
}

// DEBUGGING //

void print_map(t_map *data)
{
    int y = 0;
    while(data->map[y])
    {
        printf("%s", data->map[y]);
        y++;
    }
}

void print_objects(t_map *data)
{
    printf("Floor: %p\n", (void *)data->objects[FLOOR]);
    printf("Wall: %p\n", (void *)data->objects[FLOOR]);
    printf("Coin: %p\n", (void *)data->objects[FLOOR]);
    printf("Exit: %p\n", (void *)data->objects[FLOOR]);
    printf("Player: %p\n", (void *)data->objects[FLOOR]);
}