/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:27:08 by ilyanbendib       #+#    #+#             */
/*   Updated: 2023/12/18 12:07:34 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_draw_character(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Pacman, game->Pacman->x * SIZE, game->Pacman->y * SIZE);
}

int ft_handle_key_press(int keycode, void *param)
{
    t_game *game = (t_game *)param;

    if (keycode == ESCAPE_KEY || keycode == 53)
    {
        printf("Programme terminé.\n");
        exit(0);
    }
    else
    {
        if (keycode == Z || keycode == W)
        {
			ft_move_up(game);
        }
        else if (keycode == Q || keycode == S_QW)
        {
			ft_move_down(game);
        }
        else if (keycode == S || keycode == A)
        {
            ft_move_left(game);
        }
        else if (keycode == D || keycode == D_QW)
        {
            ft_move_right(game);
        }
    }
    return 0;
}