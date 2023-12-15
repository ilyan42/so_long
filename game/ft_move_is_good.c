/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_is_good.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:52:38 by ilyanbendib       #+#    #+#             */
/*   Updated: 2023/12/15 11:39:44 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_is_good(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1')
		return (0);
	if (game->map[x][y] == 'C')
		game->Pacman_colec += 1;
	if (game->map[y][x])
		game->nbr_move += 1;
	return (1);
}