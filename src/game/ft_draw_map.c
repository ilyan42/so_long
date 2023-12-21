/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:16 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/21 15:39:06 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	print_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Pacman_wall, x * SIZE, y
		* SIZE);
}

void	print_ground(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Pacman_gnd, x * SIZE, y
		* SIZE);
}

void	print_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Pacman_colec, x * SIZE,
		y * SIZE + 11);
}

void	print_exit(t_game *game, int x, int y)
{
	if (nb_colec_is_good(game))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->Pacman_exit_open, x * SIZE, y
		* SIZE + 11);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->Pacman_exit_close, x * SIZE, y
		* SIZE + 11);
}
