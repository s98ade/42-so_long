/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:57:57 by sade              #+#    #+#             */
/*   Updated: 2024/03/01 20:57:57 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_map  map;

    if (argc != 2)
    {
        ft_putstr_fd("Error\n Not enough arguments!\n", 2);
        exit(1);
    }
    if (!ber_file(argv[1]))
    {
        ft_putchar_fd("Error\n Invalid file type.\n .ber files only!\n", 2);
        exit(1);
    }
    map = init_map(argv[1]);
}