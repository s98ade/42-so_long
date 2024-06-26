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
    t_map  data;

    if (argc != 2)
        file_error(1);
    if (!ber_file(argv[1]))
        file_error(2);
    data = init_data(argv[1]);
    mlx_set_setting(MLX_STRETCH_IMAGE, true);
    data.window = init_window(&data);
    draw_map(&data);
   // mlx_key_hook(map->window, &key_hook, map);
    mlx_loop(data.window);
    //free(map->map);
    mlx_terminate(data.window);
    return(0);
}