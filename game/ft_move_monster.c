/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_monster.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:19:11 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/18 18:46:21 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_move_monster(t_monstre *game)
{
    int x = game->Monster_blue->x;
    int y = game->Monster_blue->y;

    while (1)
    {
		ft_printf("------------ici-----------\n");
        while (move_monster_is_good(game, x - 1, y) == 1)
        {
			ft_printf("-----------------ici----------\n");
            game->map[y][x] = '0';
            game->map[y][x - 1] = 'B';
            game->Monster_blue->x = x - 1;
        }

        while (move_monster_is_good(game, x + 1, y) == 1)
        {
            game->map[y][x] = '0';
            game->map[y][x + 1] = 'B';
            game->Monster_blue->x = x + 1;
        }
    }
}

