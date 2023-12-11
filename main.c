/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:40 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/11 18:08:56 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	t_game game;

	ft_game_init(&game);
	// ft_init_map(&game, 1);
	ft_draw_character(&game);
	//mlx_hook(game.mlx, 2, 1L << 0, ft_handle_key_press, (void *)&game);
	mlx_loop(game.win);
	return 0;
}
