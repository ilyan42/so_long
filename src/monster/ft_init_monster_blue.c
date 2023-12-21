/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_monster_blue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:36:12 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/21 15:39:41 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_draw_monster_blue(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Monster_blue,
		game->Monster_blue->x * SIZE, game->Monster_blue->y * SIZE);
}

void	ft_pos_monster_blue(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'B')
				ft_new_position_monster_blue(x, y, game);
			x++;
		}
		y++;
	}
}

void	ft_new_position_monster_blue(int x, int y, t_game *game)
{
	game->Monster_blue->x = x;
	game->Monster_blue->y = y;
}
