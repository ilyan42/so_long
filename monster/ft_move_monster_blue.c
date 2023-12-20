/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_monster_blue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:19:11 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/20 19:27:06 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_monster_is_good(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == '0')
		return (1);
	if (game->map[y][x] == 'P')
	{
		ft_printf("\n\n THE MONSTER ATE YOU !! AND YOU DEID IN %d MOVEMENT\n\n",
			game->nbr_move);
		exit(0);
	}
	return (0);
}

void	ft_move_monster_left_blue(t_game *game)
{
	int	x;
	int	y;

	x = game->Monster_blue->x;
	y = game->Monster_blue->y;
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'B';
	game->Monster_blue->x = x - 1;
}

void	ft_move_monster_right_blue(t_game *game)
{
	int	x;
	int	y;

	x = game->Monster_blue->x;
	y = game->Monster_blue->y;
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'B';
	game->Monster_blue->x = x + 1;
}

void	ft_move_monster_up_blue(t_game *game)
{
	int	x;
	int	y;

	x = game->Monster_blue->x;
	y = game->Monster_blue->y;
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'B';
	game->Monster_blue->y = y - 1;
}

void	ft_move_monster_down_blue(t_game *game)
{
	int	x;
	int	y;

	x = game->Monster_blue->x;
	y = game->Monster_blue->y;
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'B';
	game->Monster_blue->y = y + 1;
}
