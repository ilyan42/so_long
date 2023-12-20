/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_monster_red.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:19:11 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/20 14:21:48 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_monster_left_red(t_game *game)
{
	int	x;
	int	y;

	x = game->Monster_red->x;
	y = game->Monster_red->y;
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'R';
	game->Monster_red->x = x - 1;
}

void	ft_move_monster_right_red(t_game *game)
{
	int	x;
	int	y;

	x = game->Monster_red->x;
	y = game->Monster_red->y;
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'R';
	game->Monster_red->x = x + 1;
}

void	ft_move_monster_red(t_game *game)
{
	int	x;
	int	y;

	x = game->Monster_red->x;
	y = game->Monster_red->y;
	if (game->monster_red_direction == 1)
	{
		if (move_monster_is_good(game, x + 1, y))
			ft_move_monster_right_red(game);
		else
			game->monster_red_direction = -1;
	}
	else
	{
		if (move_monster_is_good(game, x - 1, y))
			ft_move_monster_left_red(game);
		else
			game->monster_red_direction = 1;
	}
}
