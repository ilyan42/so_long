/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:40 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/18 13:51:34 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(void)
{
	t_game game;
	
	ft_parsing_map(&game);
	size_map(&game);
	ft_game_init(&game);
	nb_colect_in_map(&game);
	ft_print_map(&game);
	ft_init_player(&game);
	ft_draw_character(&game);
	mlx_loop_hook(game.mlx, ft_update, (void *)&game);
	mlx_key_hook(game.win, ft_handle_key_press, (void *)&game);
	mlx_loop(game.mlx);
	return 0;
}
