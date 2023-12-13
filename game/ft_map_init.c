/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:39:28 by ilyanbendib       #+#    #+#             */
/*   Updated: 2023/12/13 12:02:02 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	ft_map_init(t_game *game)
// {
// 	// int size;
// 	// int x = 0;
// 	// int y = 0;
	
// 	// size = SIZE;
// 	// game = malloc(sizeof(t_game));

// 	// game->mlx = mlx_init();
// 	// game->win = mlx_new_window(game->mlx, 800, 600, "alex vs l'arabe");

// 	// game->ground_img = mlx_xpm_file_to_image(game->mlx, "img/ground.xpm", &size, &size);
// 	// game->character_img = mlx_xpm_file_to_image(game->mlx, "img/character.xpm", &size, &size);
// 	// game->Wall_img = mlx_xpm_file_to_image(game->mlx, "img/Wall.xpm", &size, &size);
// 	// game->Collectibles_img = mlx_xpm_file_to_image(game->mlx, "img/Colectibles.xpm", &size, &size);
// 	// game->exit_img = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm", &size, &size);

// 	// mlx_put_image_to_window(game->mlx, game->win, game->Collectibles_img, x * SIZE, y * SIZE);
// 	// mlx_put_image_to_window(game->mlx, game->win, game->character_img, x * SIZE, y * SIZE);
// 	// mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * SIZE, y * SIZE);
// 	// mlx_put_image_to_window(game->mlx, game->win, game->Wall_img, x * SIZE, y * SIZE);
// 	// mlx_put_image_to_window(game->mlx, game->win, game->ground_img, x * SIZE, y * SIZE);

// 	// ft_draw_character(game);
// 	// mlx_hook(game->win, 2, 1L << 0, ft_handle_key_press, game);
// 	// mlx_loop(game->mlx);
// }

// void ft_game_init(t_game *game)
// {
// 	int size;

// 	size = SIZE;
// 	game = malloc(sizeof(t_game));
// 	game->mlx = mlx_init();
// 	game->win = mlx_new_window(game->mlx, 800, 600, "crime buster");
// 	game->Collectibles_img = mlx_xpm_file_to_image(game->mlx, "./img/Colectibles.xpm", &size , &size);
// 	game->character_img = mlx_xpm_file_to_image(game->mlx, "./img/Charactere.xpm", &size, &size);
// 	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &size, &size);
// 	game->Wall_img = mlx_xpm_file_to_image(game->mlx, "./img/Wall.xpm", &size, &size);
// 	game->ground_img = mlx_xpm_file_to_image(game->mlx, "./img/ground.xpm", &size, &size);
// }

void ft_game_init(t_game *game)
{
    int size;

    size = SIZE;
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, 1000, 800, "crime buster");
    game->Collectibles_img = mlx_xpm_file_to_image(game->mlx, "./img/Colectibles.xpm", &size, &size);
    game->character_img = mlx_xpm_file_to_image(game->mlx, "./img/Character.xpm", &size, &size);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &size, &size);
    game->Wall_img = mlx_xpm_file_to_image(game->mlx, "./img/Wall.xpm", &size, &size);
    game->ground_img = mlx_xpm_file_to_image(game->mlx, "./img/ground.xpm", &size, &size);
}



void ft_init_map(t_game *game, int car_pos)
{
	int x;
	int y;
	int size;

	size = SIZE;
	y = -1;
	
	while(game->map[++y])
	{
		x = -1;
		while(game->map[y][++x])
		{
			if(car_pos && game->map[y][x] == 'P')
				ft_new_position(x, y, game);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->Wall_img, x * size, y * size);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->character_img, x * size, y * size);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->ground_img, x * size, y * size);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->Collectibles_img, x * size, y * size);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * size, y * size);
		}
	}
	//mlx_clear_window(game->mlx, game->win);

	//ft_print_map(game);
}

void ft_new_position(int x, int y, t_game *game)
{
	game->character_x = x;
	game->character_y = y;
}


void ft_parsing_map(t_game *game)
{
	int fd;
	int map_height = 0;
	char *tmp;

	fd = open("./map/map2.ber", O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		map_height++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);

	fd = open("./map/map2.ber", O_RDONLY);
	tmp = get_next_line(fd);
	game->map = malloc(sizeof(char*) * (map_height + 1));

	int i = 0;
	while (tmp && i < map_height)
	{
		game->map[i] = tmp;
		tmp = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}

int ft_update(t_game *game)
{
	ft_init_map(game, 1);
	ft_draw_character(game);
	return (0);
}