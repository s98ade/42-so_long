/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:05:28 by sade              #+#    #+#             */
/*   Updated: 2024/06/17 10:24:09 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_t *init_window(const t_map *data)
{
    mlx_t *window;

    window = mlx_init(BLOCK * data->map_width, BLOCK * data->map_hight, "so_long", true);
    if(!window)
    {
        ft_putstr_fd("Error\n Window initialization failed!\n", 2);
        exit(1);
    }
    return(window);
}