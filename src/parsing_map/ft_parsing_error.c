/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:34:43 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/26 13:45:25 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static char	**path_clone(char **map)
{
	int		rows;
	char	**clone;
	int		i;

	rows = 0;
	i = -1;
	while (map[rows])
		rows++;
	clone = ft_calloc(rows + 1, sizeof(char *));
	if (!clone)
		return (NULL);
	while (map[++i])
		clone[i] = ft_strdup(map[i]);
	return (clone);
}

static void	flood(int x, int y, t_game *game)
{
	if (game->map_dup[y][x] == '1' || game->map_dup[y][x] == '3')
		return ;
	game->map_dup[y][x] = '3';
	flood(x, y + 1, game);
	flood(x, y - 1, game);
	flood(x - 1, y, game);
	flood(x + 1, y, game);
	return ;
}

static int	check_collec_exit(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_dup[i])
	{
		if (ft_strchr(game->map_dup[i], 'C') || \
			ft_strchr(game->map_dup[i], 'E'))
			return (0);
		i++;
	}
	return (1);
}

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
	int	x ;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				game->collect += 1;
			if (game->map[y][x] == 'E')
				game->pacman_exit_open += 1;
			if (game->map[y][x] == 'P')
				player_position(x, y, game);
		}
	}
	game->size_x = y;
	game->size_y = x;
	// check_walls(game);
	// if (!game->player || game->player != 1)
	// 	error_game(game);
	if (!pathfinder(game))
	{
		printf("Error\nMap isn't rectangular or isn't playable\n");
		exit(0);
	}
}

int	pathfinder(t_game *game)
{
	int	is_path;
	int	nb_collec;

	nb_collec = game->collect;
	game->map_dup = path_clone(game->map);
	game->nb_moves_max = (game->size_x * game->size_y) * 2;
	game->nb_moves = 0;
	flood(game->player_position->x, game->player_position->y, game);
	is_path = check_collec_exit(game);
	// ft_free_splitted_map(game->map_dup);
	game->collect = nb_collec;
	return (is_path);
}