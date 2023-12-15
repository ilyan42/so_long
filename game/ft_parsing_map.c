/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:28:56 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/15 16:21:30 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void size_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			x++;
		}
		y++;
	}
	game->size_x = x;
	game->size_y = y;
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
	
	ft_printf("------------------------ICI--------------------\n");
	for (int y = 0; y < i; y++ )
	{
		ft_printf("%s", game->map[y]);
	}
	close(fd);
}