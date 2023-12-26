/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_error_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:30:26 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/26 17:38:22 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	player_position(int x, int y, t_game *game)
{
	game->player_position = malloc(sizeof(t_game));
	if (!game->player_position)
	{
		printf("error player position");
	}
	game->player_position->x = x;
	game->player_position->y = y;
}

void	ft_layout(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
				player_position(x, y, game);
		}
	}
	game->size_x = y;
	game->size_y = x;
	// check_walls(game);
	// if (!game->player || game->player != 1)
	// 	error_game(game);
	if (!pathfinder(game) || !is_rectangular(game))
	{
		printf("Error\nMap isn't rectangular or isn't playable\n");
		exit(0);
	}
}

void	ft_free_splitted_map(char **tab)
{
	char	**temp;

	temp = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(temp);
}
