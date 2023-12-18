/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_is_good.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:52:38 by ilyanbendib       #+#    #+#             */
/*   Updated: 2023/12/17 15:56:45 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_is_good(t_game *game, int x, int y)
{
	
	printf("   x: %d, y: %d\n", x, y);
	printf("  size_x: %d, size_y: %d\n", game->size_x, game->size_y);
	
    ft_printf("ici\n");
	if (game == NULL || game->map == NULL) {
        ft_printf("Invalid indices or uninitialized game structure\n");
        exit (0);
    }
	if (y < 0)
	{
		ft_printf("y < 0\n");
		exit (0);
	}
	if (y >= game->size_y - 1 || x >= game->size_x - 1)
	{
		ft_printf("y >= game->size_y  x >= game->size_x\n");
		exit (0);
	}
	if (x < 0)
	{
		ft_printf("x < 0\n");
		exit (0);
	}

    ft_printf("-----------------ici1---------\n");
    if (game->map[y][x] == '1') {
        ft_printf("Hit a wall\n");
        return (0);
    }

    ft_printf("-----------------ici2---------\n");
    if (game->map[y][x] == 'C') {
        ft_printf("Collected a Collectible\n");
        game->Pacman_colec += 1;
    }

    ft_printf("-----------------ici3---------\n");
    if (game->map[y][x] != '\0') {
        ft_printf("Valid move\n");
        game->nbr_move += 1;
        return (1);
    }

    ft_printf("Invalid move\n");
    return (0);
}