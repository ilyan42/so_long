/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_monster_green.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:19:11 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/21 15:40:07 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_move_monster_down_green(t_game *game)
{
	int	x;
	int	y;

	x = game->Monster_green->x;
	y = game->Monster_green->y;
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'G';
	game->Monster_green->y = y + 1;
}

void	ft_move_monster_up_green(t_game *game)
{
	int	x;
	int	y;

	x = game->Monster_green->x;
	y = game->Monster_green->y;
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'G';
	game->Monster_green->y = y - 1;
}

void	ft_move_monster_green(t_game *game)
{
	int	x;
	int	y;

	x = game->Monster_green->x;
	y = game->Monster_green->y;
	if (game->monster_green_direction == 1)
	{
		if (move_monster_is_good(game, x, y - 1))
			ft_move_monster_up_green(game);
		else
			game->monster_green_direction = -1;
	}
	else
	{
		if (move_monster_is_good(game, x, y + 1))
			ft_move_monster_down_green(game);
		else
			game->monster_green_direction = 1;
	}
}
