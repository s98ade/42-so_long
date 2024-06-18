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
    t_map  *map;

    if (argc != 2)
    {
        ft_putstr_fd("Error\nNot enough arguments!\n", 2);
        exit(1);
    }
    if (!ber_file(argv[1]))
    {
        ft_putstr_fd("Error\nInvalid file type.\n .ber files only!\n", 2);
        exit(1);
    }
    map = read_map(argv[1]);
    mlx_set_setting(MLX_STRETCH_IMAGE, true);
    map->window = init_window(map);
   // mlx_key_hook(map->window, &key_hook, map);
    mlx_loop(map->window);
    //free(map->map);
    mlx_terminate(map->window);
    return(0);
}