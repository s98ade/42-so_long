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
    data.window = init_window(&data);
    mlx_set_setting(MLX_STRETCH_IMAGE, true);
    init_texture(data.imgs, &data);
    init_images(data.imgs, data.window, &data);
    validate_path(&data);
    // making drawing for each instance seperatly
    draw_map(&data, data.window);
    //
    mlx_key_hook(data.window, &key_hook, &data);
    mlx_loop(data.window);
    //free_map(data.map);
    mlx_terminate(data.window);
    return(0);
}
