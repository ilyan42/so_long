/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:40 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/21 15:50:10 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		ft_parsing_map(av[1], &game);
		size_map(&game);
		ft_game_init(&game);
		ft_check_map(&game);
		nb_colect_in_map(&game);
		ft_print_map(&game);
		ft_init_player(&game);
		ft_pos_monster_blue(&game);
		ft_pos_monster_green(&game);
		ft_pos_monster_red(&game);
		ft_draw_pacman_down(&game);
		ft_draw_monster_blue(&game);
		ft_draw_monster_green(&game);
		ft_draw_monster_red(&game);
		mlx_loop_hook(game.mlx, ft_update, (void *)&game);
		mlx_hook(game.win, KEY_PRESS, KEY_PRESS_MASK, ft_handle_key_press,
			(void *)&game);
		mlx_loop(game.mlx);
	}
	return (0);
}
