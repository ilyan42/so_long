/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:39:28 by ilyanbendib       #+#    #+#             */
/*   Updated: 2023/12/20 19:12:04 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_window(t_game *game, int img_size)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->height * img_size, game->width
			* img_size, "Pacman");
}

void	load_images(t_game *game, int img_size)
{
	game->Pacman_colec = mlx_xpm_file_to_image(game->mlx, "./img/colec.xpm",
			&img_size, &img_size);
	game->Pacman = mlx_xpm_file_to_image(game->mlx, "./img/pacman_right.xpm",
			&img_size, &img_size);
	game->Pacman_exit = mlx_xpm_file_to_image(game->mlx, "./img/exit_pac.xpm",
			&img_size, &img_size);
	game->Pacman_wall = mlx_xpm_file_to_image(game->mlx, "./img/Walll.xpm",
			&img_size, &img_size);
	game->Pacman_gnd = mlx_xpm_file_to_image(game->mlx, "./img/ground_pac.xpm",
			&img_size, &img_size);
	game->Monster_red = mlx_xpm_file_to_image(game->mlx,
			"./img/Monster_red.xpm", &img_size, &img_size);
	game->Monster_green = mlx_xpm_file_to_image(game->mlx,
			"./img/Monster_green.xpm", &img_size, &img_size);
	game->Monster_blue = mlx_xpm_file_to_image(game->mlx,
			"./img/Monster_blue.xpm", &img_size, &img_size);
	game->Pacman_up = mlx_xpm_file_to_image(game->mlx, "./img/pacman_up.xpm",
			&img_size, &img_size);
	game->Pacman_left = mlx_xpm_file_to_image(game->mlx,
			"./img/pacman_left.xpm", &img_size, &img_size);
	game->Pacman_down = mlx_xpm_file_to_image(game->mlx,
			"./img/pacman_down.xpm", &img_size, &img_size);
}

void	initialize_game(t_game *game)
{
	game->nbr_move = 0;
	game->nbr_colec = 0;
	game->nbr_colect_in_map = 0;
	game->monster_direction = 1;
	game->monster_green_direction = 0;
	game->monster_red_direction = 0;
	game->height = game->size_x;
	game->width = game->size_y;
}

void	ft_game_init(t_game *game)
{
	int	img_size;

	img_size = SIZE;
	initialize_game(game);
	initialize_window(game, img_size);
	load_images(game, img_size);
	mlx_clear_window(game->mlx, game->win);
}

int	ft_update(t_game *game)
{
	static int	count;

	count++;
	if (count == 5000)
	{
		ft_print_map(game);
		ft_move_monster_blue(game);
		ft_move_monster_green(game);
		ft_move_monster_red(game);
		ft_print_movements(game);
		count = 0;
	}
	return (0);
}
