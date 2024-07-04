/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:05:31 by sofia             #+#    #+#             */
/*   Updated: 2024/07/04 13:56:24 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool is_wall(t_map *data, t_move move)
{
    int x;
    int y;

    x = data->imgs->img_player->instances[0].x / BLOCK;
    y = data->imgs->img_player->instances[0].y / BLOCK;
    if(move == UP && data->map[y - 1][x] == '1')
        return(true);
    else if(move == DOWN && data->map[y + 1][x] == '1')
        return(true);
    else if(move == LEFT && data->map[y][x - 1] == '1')
        return(true);
    else if(move == RIGHT && data->map[y][x + 1] == '1')
        return(true);
    print_steps();
    return(false);
}

void is_exit(t_map *data)
{
    int x;
    int y;
    
    x = data->imgs->img_player->instances[0].x / BLOCK;
    y = data->imgs->img_player->instances[0].y / BLOCK;
    if(data->collected == data->count->c)
    {
        if(data->map[y][x] == 'E')
        {
            data->imgs->img_player->instances[0].enabled = false;
            ft_printf("Hurray! You won!\n");
            mlx_close_window(data->window);
        }
    }
}
void is_collectable(t_map *data)
{
    int x;
    int y;
    int i;
    
    i = 0;
    x = data->imgs->img_player->instances[0].x;
    y = data->imgs->img_player->instances[0].y;
    if(data->map[y / BLOCK][x / BLOCK] == 'C')
    {
        while(i < data->count->c)
        {
            if(x == data->imgs->img_coin->instances[i].x && y == data->imgs->img_coin->instances[i].y)
            {
                data->imgs->img_coin->instances[i].enabled = false;
                data->map[y / BLOCK][x / BLOCK] = '0';
                data->collected++;
            }
            i++;
        }
    }
}
