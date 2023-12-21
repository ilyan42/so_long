/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_monster_red.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:14:40 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/21 15:39:51 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_draw_monster_red(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Monster_red,
		game->Monster_red->x * SIZE, game->Monster_red->y * SIZE);
}

void	ft_pos_monster_red(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'R')
				ft_new_position_monster_red(x, y, game);
			x++;
		}
		y++;
	}
}

void	ft_new_position_monster_red(int x, int y, t_game *game)
{
	game->Monster_red->x = x;
	game->Monster_red->y = y;
}
