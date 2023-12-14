/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:39:28 by ilyanbendib       #+#    #+#             */
/*   Updated: 2023/12/14 14:26:04 by ilbendib         ###   ########.fr       */
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
    game->Collectibles_img = mlx_xpm_file_to_image(game->mlx, "./img/colec.xpm", &img_size, &img_size);
    game->character_img = mlx_xpm_file_to_image(game->mlx, "./img/pacmanv3.xpm", &img_size, &img_size);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "./img/exit_pac.xpm", &img_size, &img_size);
    game->Wall_img = mlx_xpm_file_to_image(game->mlx, "./img/Walll.xpm", &img_size, &img_size);
    game->ground_img = mlx_xpm_file_to_image(game->mlx, "./img/ground_pac.xpm", &img_size, &img_size);
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
				mlx_put_image_to_window(game->mlx, game->win, game->Wall_img, x * img_size, y * img_size);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->character_img, x * img_size, y * img_size);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->ground_img, x * img_size, y * img_size);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->Collectibles_img, x * img_size, y * img_size);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * img_size, y * img_size);
		}
	}
}

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

void ft_new_position(int x, int y, t_game *game)
{
	game->character_x = x;
	game->character_y = y;
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

int ft_update(t_game *game)
{
	ft_init_map(game);
	ft_draw_character(game);
	return (0);
}