/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_error_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:14:38 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/27 18:20:09 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_valid_first_or_last_line(char *line, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len - 1)
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_first_line(t_game *game)
{
	size_t	len;

	if (!game->map[0] || (len = ft_strlen(game->map[0])) < 2
		|| !is_valid_first_or_last_line(game->map[0], len))
	{
		ft_printf("Error\nNo map or invalid first line\n");
		close_game(game);
	}
}

void	check_last_line(t_game *game)
{
	size_t	len;
	int		y;

	y = 0;
	while (game->map[y + 1] != NULL)
		y++;
	if (y > 0 && (len = ft_strlen(game->map[y])) >= 2
		&& is_valid_first_or_last_line(game->map[y], len))
		return ;
	ft_printf("Error\nError Wall_last_line\n");
	close_game(game);
}

void	check_walls(t_game *game)
{
	int		y;
	size_t	len;

	y = 0;
	check_first_line(game);
	check_walls2(game);
	len = ft_strlen(game->map[0]);
	while (game->map[y])
	{
		if (ft_strlen(game->map[0]) != len)
		{
			ft_printf("Error\nError line\n");
			close_game(game);
		}
		if (y > 0 && game->map[y + 1] == NULL)
			check_last_line(game);
		else
		{
			if (game->map[y][0] != '1' || game->map[y][len - 2] != '1')
			{
				ft_printf("Error\nError line\n");
				close_game(game);
			}
		}
		y++;
	}
}
