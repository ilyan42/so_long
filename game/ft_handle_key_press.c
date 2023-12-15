/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:27:08 by ilyanbendib       #+#    #+#             */
/*   Updated: 2023/12/14 16:50:45 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_draw_character(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->Pacman, game->Pacman_x, game->Pacman_y);
}

int ft_handle_key_press(int keycode, void *param)
{
    t_game *game = (t_game *)param;

    if (keycode == ESCAPE_KEY)
    {
        printf("Programme terminé.\n");
        exit(0);
    }
    else
    {
        printf("Touche appuyée : %d\n", keycode);

        if (keycode == 97)
        {
            game->Pacman_x -= SIZE;
			ft_draw_character(game);
        }
        else if (keycode == 115)
        {
            game->Pacman_y -= SIZE;
			ft_draw_character(game);
        }
        else if (keycode == 110)
        {
            game->Pacman_x += SIZE;
			ft_draw_character(game);
        }
        else if (keycode == 119)
        {
            game->Pacman_y += SIZE;
			ft_draw_character(game);
        }
        
    }
    return 0;
}