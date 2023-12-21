/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_monster_green.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:14:40 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/21 15:39:44 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_draw_monster_green(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Monster_green,
		game->Monster_green->x * SIZE, game->Monster_green->y * SIZE);
}

void	ft_pos_monster_green(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'G')
				ft_new_position_monster_green(x, y, game);
			x++;
		}
		y++;
	}
}

void	ft_new_position_monster_green(int x, int y, t_game *game)
{
	game->Monster_green->x = x;
	game->Monster_green->y = y;
}
