/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:49:36 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/09 17:55:05 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"

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
	char	**map;
}	t_game;

// typedef		struct m_map
// {
// 	char	**map;
// }	t_map;

#define KEY_PRESS 2
#define KEY_RELEASE 3
#define KEY_PRESS_MASK (1L<<0)
#define ESCAPE_KEY 53
#define TITLE_SIZE 48
#define SIZE 48

int ft_handle_key_press(int keycode, void *param);
void ft_draw_character(t_game *game);
void	ft_map_init(t_game *game);
void	ft_print_map(t_game *game);

#endif