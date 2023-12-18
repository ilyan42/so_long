/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:39:28 by ilyanbendib       #+#    #+#             */
/*   Updated: 2023/12/18 16:07:47 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_game_init(t_game *game)
{
    int img_size;
    img_size = SIZE; 
	
	game->nbr_move = 0;
	game->nbr_colec = 0;
	game->nbr_colect_in_map = 0;
	game->height = game->size_x;
	game->width = game->size_y;	
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->height * img_size, game->width * img_size, "Pacman");
    game->Pacman_colec = mlx_xpm_file_to_image(game->mlx, "./img/colec.xpm", &img_size, &img_size);
    game->Pacman = mlx_xpm_file_to_image(game->mlx, "./img/pacmanv3.xpm", &img_size, &img_size);
    game->Pacman_exit = mlx_xpm_file_to_image(game->mlx, "./img/exit_pac.xpm", &img_size, &img_size);
    game->Pacman_wall = mlx_xpm_file_to_image(game->mlx, "./img/Walll.xpm", &img_size, &img_size);
    game->Pacman_gnd = mlx_xpm_file_to_image(game->mlx, "./img/ground_pac.xpm", &img_size, &img_size);
	game->Monster_red = mlx_xpm_file_to_image(game->mlx, "./img/Monster_red.xpm", &img_size, &img_size);
	game->Monster_green = mlx_xpm_file_to_image(game->mlx, "./img/Monster_green.xpm", &img_size, &img_size);
	game->Monster_blue = mlx_xpm_file_to_image(game->mlx, "./img/Monster_blue.xpm", &img_size, &img_size);
}

void	ft_init_player(t_game *game)
{
	int			x;
	int			y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				ft_new_position(x, y, game);
			x++;
		}
		y++;
	}
	ft_print_map(game);
}

void ft_print_map(t_game *game)
{
	int x;
	int y;
	int img_size;

	img_size = SIZE;
	y = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->Pacman_wall, x * img_size, y * img_size);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->Pacman_gnd, x * img_size, y * img_size);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->Pacman_colec, x * img_size, y * img_size + 11);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->Pacman_exit, x * img_size, y * img_size + 11);
			if (game->map[y][x] == 'R')
				mlx_put_image_to_window(game->mlx, game->win, game->Monster_red, x * img_size, y * img_size);
			if (game->map[y][x] == 'G')
				mlx_put_image_to_window(game->mlx, game->win, game->Monster_green, x * img_size, y * img_size);
			if (game->map[y][x] == 'B')
				mlx_put_image_to_window(game->mlx, game->win, game->Monster_blue, x * img_size, y * img_size);
			x++;
		}
		y++;
	}
}

void ft_new_position(int x, int y, t_game *game)
{
	game->Pacman->x = x;
	game->Pacman->y = y;
}

int ft_update(t_game *game)
{
	ft_print_map(game);
	ft_draw_character(game);
	return (0);
}