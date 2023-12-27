/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_error_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:30:26 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/27 17:42:52 by ilbendib         ###   ########.fr       */
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

size_t	ft_search_wall(const char *s, const char *item)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(item, s[i]) == 0)
			break ;
		++i;
	}
	return (i);
}
#include <stdio.h>

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
        while (x < game->width)
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

int check_wall_up(char **map)
{
	int x;

	x = 0;
	while(map[0][x] != '\0')
	{
		if (map[0][x] != '1')
			return (0);
		x++;
	}
	return(1);
}

// void	check_walls(t_game *game)
// {
// 	int		y;
// 	size_t	len;

// 	y = 0;
// 	if (!game->map[0])
// 	{
// 		ft_printf("no map");
// 		close_game(game);
// 	}
// 	len = ft_strlen(game->map[0]);
// 	check_walls2(game);
// 	// if (game->map[0][ft_strlen(game->map[0]) - 2] != '1')
// 	// {
// 	// 	ft_printf("Error\nError Wall_first_line\n");
// 	// 	close_game(game);
// 	// }
// 	while (game->map[y])
// 	{
// 		if ((game->map[y][0] != '1' || game->map[y][len - 2] != '1'))
// 		{
// 			ft_printf("Error\nError line\n");
// 			close_game(game);
// 		}
// 		y++;
// 	}
// }

// void check_walls(t_game *game)
// {
//     int y;
//     size_t len;

//     y = 0;
//     if (!game->map[0] || (len = ft_strlen(game->map[0])) < 2)
//     {
//         ft_printf("Error\nNo map or invalid first line\n");
//         close_game(game);
//     }
//     check_walls2(game);

//     while (game->map[y])
//     {
//         if (y == 0)  // Pour la première ligne
//         {
//             size_t i = 0;
//             while (i < len - 1)  // Notez le -1 pour éviter le caractère de fin de ligne
//             {
//                 if (game->map[y][i] != '1')
//                 {
//                     ft_printf("Error\nError Wall_first_line\n");
//                     close_game(game);
//                 }
//                 i++;
//             }
//         }
//         else  // Pour le reste des lignes
//         {
//             if (game->map[y][0] != '1' || game->map[y][len - 2] != '1')
//             {
//                 ft_printf("Error\nError line\n");
//                 close_game(game);
//             }
//         }

//         y++;
//     }

//     // Le reste de votre code ici...
// }

#include <stddef.h>

int is_valid_first_or_last_line(char *line, size_t len)
{
    size_t i = 0;
    while (i < len - 1)
    {
        if (line[i] != '1')
            return 0;  // Si un caractère différent de '1' est trouvé, retourne faux
        i++;
    }
    return 1;  // Si tous les caractères sont '1', retourne vrai
}

void check_first_line(t_game *game)
{
    size_t len;
    if (!game->map[0] || (len = ft_strlen(game->map[0])) < 2 || !is_valid_first_or_last_line(game->map[0], len))
    {
        ft_printf("Error\nNo map or invalid first line\n");
        close_game(game);
    }
}

void check_last_line(t_game *game)
{
    size_t len;
    int y = 0;
    while (game->map[y + 1] != NULL)
        y++;
    
    if (y > 0 && (len = ft_strlen(game->map[y])) >= 2 && is_valid_first_or_last_line(game->map[y], len))
        return;

    ft_printf("Error\nError Wall_last_line\n");
    close_game(game);
}

void check_walls(t_game *game)
{
    int y;
    size_t len;

    y = 0;
    check_first_line(game);
    check_walls2(game);

    while (game->map[y])
    {
        if (y > 0 && game->map[y + 1] == NULL)
        {
            check_last_line(game);
        }
        else
        {
            len = ft_strlen(game->map[y]);
            if (game->map[y][0] != '1' || game->map[y][len - 2] != '1')
            {
                ft_printf("Error\nError line\n");
                close_game(game);
            }
        }

        y++;
    }

    // Le reste de votre code ici...
}




