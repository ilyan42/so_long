/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:28:56 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/20 19:23:34 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	size_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			x++;
		}
		y++;
	}
	game->size_x = x;
	game->size_y = y;
}

void	count_map_height(t_game *game, int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		game->map_height++;
		free(tmp);
		tmp = get_next_line(fd);
	}
}

void	allocate_and_fill_map(t_game *game, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = get_next_line(fd);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	while (tmp && i < game->map_height)
	{
		game->map[i] = ft_strdup(tmp);
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
}

void	ft_parsing_map(t_game *game)
{
	int	fd;

	fd = open("./map/map2.ber", O_RDONLY);
	count_map_height(game, fd);
	close(fd);
	fd = open("./map/map2.ber", O_RDONLY);
	allocate_and_fill_map(game, fd);
	close(fd);
}
