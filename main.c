/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:40 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/07 18:48:58 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef		struct s_game
{
	void *mlx;
    void *win;
	void	*ground_img;
	void	*character_img;
	void	*Wall_img;
	void	*Collectibles_img;
	void	*exit_img;
	int		character_x;
	int		character_y;
}	t_game;

#define KEY_PRESS 2
#define KEY_RELEASE 3
#define KEY_PRESS_MASK (1L<<0)
#define ESCAPE_KEY 53
#define TITLE_SIZE 48

void draw_character(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->win, game->character_img, game->character_x, game->character_y);
}

int handle_key_press(int keycode, void *param)
{
	t_game *game = (t_game *)param;
	
    if (keycode == ESCAPE_KEY)
    {
        printf("Programme terminé.\n");
        exit(0);
    }
    else if (keycode == 0)
    {
		game->character_x -= TITLE_SIZE;
        draw_character(game);
    }
	else if (keycode == 13)
    {
		game->character_y -= TITLE_SIZE;
        draw_character(game);
    }
	else if (keycode == 2)
    {
		game->character_x += TITLE_SIZE;
    	draw_character(game);
    }
	else if (keycode == 1)
    {
		game->character_y += TITLE_SIZE;
        draw_character(game);
    }
    return 0;
}

int main(void)
{
	t_game game;
	int img_width, img_height;
	
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 800, 600, "Example");
    mlx_hook(game.win, KEY_PRESS, KEY_PRESS_MASK, handle_key_press, NULL);
	
	game.ground_img = mlx_xpm_file_to_image(game.mlx, "img/ground.xpm", &img_width, &img_height);
	game.character_img = mlx_xpm_file_to_image(game.mlx, "img/character.xpm", &img_width, &img_height);
	game.Wall_img = mlx_xpm_file_to_image(game.mlx, "img/Wall.xpm", &img_width, &img_height);
	game.Collectibles_img = mlx_xpm_file_to_image(game.mlx, "img/Colectibles.xpm", &img_width, &img_height);
	game.exit_img = mlx_xpm_file_to_image(game.mlx, "img/exit.xpm", &img_width, &img_height);
	
	// mlx_put_image_to_window(game.mlx, game.win, game.character_img, 250, 250);
	mlx_put_image_to_window(game.mlx, game.win, game.Collectibles_img, 150, 150);
	mlx_put_image_to_window(game.mlx, game.win, game.exit_img, 500, 500);
	mlx_put_image_to_window(game.mlx, game.win, game.Wall_img, 350, 350);
	mlx_put_image_to_window(game.mlx, game.win, game.ground_img, 0, 0);
    // mlx_loop(game.mlx);

	game.character_x = 250;
	game.character_y = 250;
	
	draw_character(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_key_press, &game);
	mlx_loop(game.mlx);
	
    return 0;
}
