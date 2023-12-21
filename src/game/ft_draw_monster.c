/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_monster.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:09:42 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/21 15:39:09 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	print_red_monster(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Monster_red, x * SIZE, y
		* SIZE);
}

void	print_green_monster(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Monster_green, x * SIZE,
		y * SIZE);
}

void	print_blue_monster(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Monster_blue, x * SIZE,
		y * SIZE);
}
