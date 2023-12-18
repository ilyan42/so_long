/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_colect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:46:24 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/18 17:01:23 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	nb_colect_in_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->nbr_colect_in_map += 1;
			x++;
		}
		y++;
	}
}

void ft_pos_mnster_red(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'B')
				ft_new_position_monster(x, y, game);
			x++;
		}
		y++;
	}
}

void ft_new_position_monster(int x, int y, t_game *game)
{
	game->Monster_blue->x = x;
	game->Monster_blue->y = y;
}