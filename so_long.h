/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:49:36 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/17 15:52:45 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <fcntl.h>
#include "LIBFT/libft.h"


typedef		struct s_pos
{
	int x;
	int y;
}		t_pos;

typedef		struct s_game
{
	void *mlx;
	void *win;
	void	*Pacman_gnd;
	t_pos	*Pacman;
	void	*Pacman_wall;
	void	*Pacman_colec;
	void	*Pacman_exit;
	char	**map;
	int		map_height;
	int		size_x;
	int		size_y;
	int		height;
	int		width;
	void	*nbr_move;
}	t_game;


#define KEY_PRESS 2
#define KEY_RELEASE 3
#define KEY_PRESS_MASK (1L<<0)
#define ESCAPE_KEY 65307
#define SIZE 50

int ft_handle_key_press(int keycode, void *param);
void ft_draw_character(t_game *game);
void	ft_map_init(t_game *game);
void	ft_print_map(t_game *game);
void	ft_print_map(t_game *game);
void ft_new_position(int x, int y, t_game *game);
void ft_init_player(t_game *game);
void ft_game_init(t_game *game);
void	ft_parsing_map(t_game *game);
int	ft_update(t_game *game);
void size_map(t_game *game);
int		move_is_good(t_game *game, int x, int y);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_up(t_game *game);
void	ft_init(t_game *game);
void ft_print_map(t_game *game);

#endif