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
        ft_putstr_fd("Error\n File couldn't be opened!\n", 2);
        close(fd);
        exit(1);
    }
    return(fd);
}