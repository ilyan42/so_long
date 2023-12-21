/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pacman.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:19:06 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/21 15:39:13 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_draw_pacman_right(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Pacman, game->Pacman->x
		* SIZE, game->Pacman->y * SIZE);
}

void	ft_draw_pacman_left(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Pacman_left,
		game->Pacman->x * SIZE, game->Pacman->y * SIZE);
}

void	ft_draw_pacman_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Pacman_up,
		game->Pacman->x * SIZE, game->Pacman->y * SIZE);
}

void	ft_draw_pacman_down(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Pacman_down,
		game->Pacman->x * SIZE, game->Pacman->y * SIZE);
}
