/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:40 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/07 16:54:28 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	close(t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "ilyan game");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x000000FF);

// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
// 	mlx_loop(vars.mlx);
// }

#define KEY_PRESS 2
#define KEY_RELEASE 3
#define KEY_PRESS_MASK (1L<<0)
#define ESCAPE_KEY 53

int handle_key_press(int keycode)
{
    if (keycode == ESCAPE_KEY)
    {
        printf("Programme terminé.\n");
        exit(0);
    }
    else
    {
        printf("Key pressed: %d\n", keycode);
    }
    return 0;
}

int main(void)
{
    void *mlx;
    void *win;
	void	*ground_img = NULL;
	void	*character_img = NULL;
	void	*Wall_img = NULL;
	void	*Collectibles_img = NULL;
	int	size = 48;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "Example");
    mlx_hook(win, KEY_PRESS, KEY_PRESS_MASK, handle_key_press, NULL);
	ground_img = mlx_xpm_file_to_image(mlx, "img/ground.xpm", &size, &size);
	character_img = mlx_xpm_file_to_image(mlx, "img/character.xpm", &size, &size);
	Wall_img = mlx_xpm_file_to_image(mlx, "img/Wall.xpm", &size, &size);
	Collectibles_img = mlx_xpm_file_to_image(mlx, "img/Colectibles.xpm", &size, &size);
	mlx_put_image_to_window(mlx, win, character_img, 250, 250);
	mlx_put_image_to_window(mlx, win, Collectibles_img, 150, 150);
	mlx_put_image_to_window(mlx, win, Wall_img, 350, 350);
	mlx_put_image_to_window(mlx, win, ground_img, 0, 0);
    mlx_loop(mlx);
    return 0;
}