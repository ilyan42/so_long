/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:53:09 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/15 11:36:55 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_left(t_game *game)
{
	int x;
	int y;

	x = game->Pacman_x;
	y = game->Pacman_y;
	if (move_is_good(game, x - 1, y))
	{
		
	}
}