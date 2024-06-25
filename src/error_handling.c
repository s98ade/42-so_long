/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:26:22 by sofia             #+#    #+#             */
/*   Updated: 2024/06/25 20:43:23 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void file_error(int nbr)
{
    if(nbr == 1)
    {
        ft_putstr_fd("Error\nNot enough arguments!\nPlease include a .ber file!\n", 2);
        exit(1);
    }
    else if(nbr == 2)
    {
        ft_putstr_fd("Error\nInvalid file type.\n.ber files only!\n", 2);
        exit(1);
    }
    else if(nbr == 3)
    {
        ft_putstr_fd("Error\nEmpty file!\n", 2);
        exit(1);
    }
    else if(nbr == 4)
    {
        ft_putstr_fd("Error\nMemory allocation failed!\ntype: objects", 2);
        exit(1);
    }
}

void map_error(int nbr, char *line)
{
    if(nbr == 1)
    {
        ft_putstr_fd("Error\nMap reading failed!", 2);
        exit(1);
    }
    else if(nbr == 2)
    {
        ft_putstr_fd("Error\n Window initialization failed!\n", 2);
        exit(1);
    }
    else if(nbr == 3)
    {
        ft_putstr_fd("Error\nRead error!\n", 2);
        exit(1);
    }
    else if(nbr == 4)
    {
        ft_putstr_fd("Error\nMap is invalid!\ntype: SHAPE", 2);
        free(line);
        exit(1);
    }
    else if(nbr == 5)
    {
        ft_putstr_fd("Error\nInvalid borders!\n", 2);
        exit(1);
    }
    else if(nbr == 6)
    {
        ft_putstr_fd("Error\nMap invalid!\ntype: SYMBOLS\n", 2);
        exit(1);
    }
}