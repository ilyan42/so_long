/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:40 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/13 13:21:44 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(void)
{
	t_game game;

	ft_parsing_map(&game);
	ft_game_init(&game);
	ft_init_map(&game);
	ft_draw_character(&game);
	mlx_loop_hook(game.mlx, ft_update, (void *)&game);
	//mlx_hook(game.win, 2, KEY_PRESS_MASK, ft_handle_key_press, &game);
	//mlx_key_hook(game.win, ft_handle_key_press, (void *)&game);
	mlx_loop(&game.mlx);
	return 0;
}
