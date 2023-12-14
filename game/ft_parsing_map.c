/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:28:56 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/14 15:38:56 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void size_map(t_game *game)
{
	int x;
	int y;

	y = -1;
	while(game->map[++y])
	{
		x = -1;
		while(game->map[y][++x])
		{
			game->size_x = x;
		}
		game->size_y = y;
	}
}

void ft_parsing_map(t_game *game)
{
	int fd;	
	char *tmp;
	game->map_height = 0;
	
	fd = open("./map/map2.ber", O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		game->map_height++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);

	fd = open("./map/map2.ber", O_RDONLY);
	tmp = get_next_line(fd);
	game->map = malloc(sizeof(char*) * (game->map_height + 1));

	int i = 0;
	while (tmp && i < game->map_height)
	{
		game->map[i] = tmp;
		tmp = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}