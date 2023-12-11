/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:39:28 by ilyanbendib       #+#    #+#             */
/*   Updated: 2023/12/11 10:55:06 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_init(t_game *game)
{
	int size;
	int x = 0;
	int y = 0;
	
	size = SIZE;
	game = malloc(sizeof(t_game));

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 800, 600, "alex vs l'arabe");

	game->ground_img = mlx_xpm_file_to_image(game->mlx, "img/ground.xpm", &size, &size);
	game->character_img = mlx_xpm_file_to_image(game->mlx, "img/character.xpm", &size, &size);
	game->Wall_img = mlx_xpm_file_to_image(game->mlx, "img/Wall.xpm", &size, &size);
	game->Collectibles_img = mlx_xpm_file_to_image(game->mlx, "img/Colectibles.xpm", &size, &size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm", &size, &size);

	mlx_put_image_to_window(game->mlx, game->win, game->Collectibles_img, x * SIZE, y * SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->character_img, x * SIZE, y * SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * SIZE, y * SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->Wall_img, x * SIZE, y * SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->ground_img, x * SIZE, y * SIZE);

	ft_draw_character(game);
	mlx_hook(game->win, 2, 1L << 0, ft_handle_key_press, game);
	mlx_loop(game->mlx);
}