/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:39:28 by ilyanbendib       #+#    #+#             */
/*   Updated: 2023/12/14 16:49:46 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_game_init(t_game *game)
{
    int img_size;
    img_size = SIZE; 
	
	game->height = game->size_x;
	game->width = game->size_y;
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->height * img_size, game->width * img_size, "crime buster");
    game->Pacman_colec = mlx_xpm_file_to_image(game->mlx, "./img/colec.xpm", &img_size, &img_size);
    game->Pacman = mlx_xpm_file_to_image(game->mlx, "./img/pacmanv3.xpm", &img_size, &img_size);
    game->Pacman_exit = mlx_xpm_file_to_image(game->mlx, "./img/exit_pac.xpm", &img_size, &img_size);
    game->Pacman_wall = mlx_xpm_file_to_image(game->mlx, "./img/Walll.xpm", &img_size, &img_size);
    game->Pacman_gnd = mlx_xpm_file_to_image(game->mlx, "./img/ground_pac.xpm", &img_size, &img_size);
}

void ft_init_map(t_game *game)
{
	int x;
	int y;
	int img_size;

	img_size = SIZE;
	y = -1;
	
	while(game->map[++y])
	{
		x = -1;
		while(game->map[y][++x])
		{
			// if(car_pos && game->map[y][x] == 'P')
			// 	ft_new_position(x, y, game);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->Pacman_wall, x * img_size, y * img_size);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->Pacman, x * img_size, y * img_size);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->Pacman_gnd, x * img_size, y * img_size);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->Pacman_colec, x * img_size, y * img_size + 11);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->Pacman_exit, x * img_size, y * img_size + 11);
		}
	}
}

void ft_new_position(int x, int y, t_game *game)
{
	game->Pacman_x = x;
	game->Pacman_y = y;
}

int ft_update(t_game *game)
{
	ft_init_map(game);
	ft_draw_character(game);
	return (0);
}