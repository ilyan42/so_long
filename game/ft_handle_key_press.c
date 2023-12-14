/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:27:08 by ilyanbendib       #+#    #+#             */
/*   Updated: 2023/12/14 13:04:31 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_draw_character(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->character_img, game->character_x, game->character_y);
}

int ft_handle_key_press(int keycode, void *param)
{
	t_game *game = (t_game *)param;
	
	if (keycode == ESCAPE_KEY)
	{
		printf("Programme terminé.\n");
		exit(0);
	}
	else if (keycode == 0)
	{
		game->character_x -= SIZE;
		ft_draw_character(game);
	}
	else if (keycode == 13)
	{
		game->character_y -= SIZE;
		ft_draw_character(game);
	}
	else if (keycode == 2)
	{
		game->character_x += SIZE;
		ft_draw_character(game);
	}
	else if (keycode == 1)
	{
		game->character_y += SIZE;
		ft_draw_character(game);
	}
	return 0;
}