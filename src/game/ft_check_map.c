/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:23:59 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/21 15:39:04 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_check_map_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				game->map_player += 1;
			x++;
		}
		y++;
	}
}

void	ft_check_map_colec(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->map_colect += 1;
			x++;
		}
		y++;
	}
}

void	ft_check_map_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				game->map_exit += 1;
			x++;
		}
		y++;
	}
}

void	ft_check_map(t_game *game)
{
	ft_check_map_colec(game);
	ft_check_map_exit(game);
	ft_check_map_player(game);

	if (game->map_colect == 0)
	{
		ft_printf("ERROR 1");
		exit(0);
	}
	if (game->map_exit != 1)
	{
		ft_printf("ERROR 2");
		exit(0);
	}
	if (game->map_player != 1)
	{
		ft_printf("ERROR 3");
		exit(0);
	}
}
