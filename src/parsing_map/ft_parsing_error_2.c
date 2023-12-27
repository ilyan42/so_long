/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_error_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:30:26 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/27 18:16:35 by ilbendib         ###   ########.fr       */
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
	check_walls(game);
	if (!pathfinder(game) || !is_rectangular(game))
	{
		printf("Error\nMap isn't rectangular or isn't playable\n");
		close_game(game);
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

int is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'E' || c == 'C' || c == 'P')
		return (1);
	return (0);
}

void check_walls2(t_game *game)
{
	int x, y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x <= game->width)
		{
			if (is_valid_char(game->map[y][x]) == 0)
			{
				ft_printf("Error\nmaaap\n");
				close_game(game);
			}
			x++;
		}
		y++;
	}
}
