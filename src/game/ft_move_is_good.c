/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_is_good.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:52:38 by ilyanbendib       #+#    #+#             */
/*   Updated: 2023/12/26 14:43:35 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	nb_colec_is_good(t_game *game)
{
	
	if (game->nbr_colect_in_map == game->nbr_colec)
	{
		return (1);
	}
	return (0);
}

int	move_is_good(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'C')
	{
		game->nbr_colec += 1;
		return (1);
	}
	if (game->map[y][x] == '0')
		return (1);
	if (game->map[y][x] == 'R' || game->map[y][x] == 'G'
		|| game->map[y][x] == 'B')
	{
		ft_printf("\n\nYOU DEID IN %d MOVEMENT\n\n", game->nbr_move);
		// exit(0);
		close_game(game);
	}
	if (game->map[y][x] == 'E')
	{
		if (nb_colec_is_good(game))
		{
			ft_printf("\n\nYOU WON IN %d MOVEMENT\n\n", game->nbr_move);
			// exit(0);
			close_game(game);
		}
	}
	return (0);
}
