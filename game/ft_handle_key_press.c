/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:27:08 by ilyanbendib       #+#    #+#             */
/*   Updated: 2023/12/17 14:31:36 by ilyanbendib      ###   ########.fr       */
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
        printf("Touche appuyée : %d\n", keycode);

        if (keycode == 13)
        {
			ft_move_up(game);
        }
        else if (keycode == 1)
        {
			ft_move_down(game);
        }
        else if (keycode == 0)
        {
            ft_move_left(game);
        }
        else if (keycode == 2)
        {
            ft_move_right(game);
        }
    }
    return 0;
}