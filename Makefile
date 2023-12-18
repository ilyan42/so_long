# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:49:42 by ilbendib          #+#    #+#              #
#    Updated: 2023/12/18 13:52:27 by ilbendib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_SRCS = 		main.c 	game/ft_map_init.c\
						game/ft_handle_key_press.c\
						game/ft_parsing_map.c\
						game/ft_move_is_good.c\
						game/ft_move.c\
						game/ft_nb_colect.c\

SRC_DIR = .

SRCS = $(_SRCS:%=$(SRC_DIR)/%)

_HEADERS = so_long.h

HEADERS_DIR = .

HEADERS = $(_HEADERS:%=$(HEADERS_DIR)/%)

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LDFLAGS = -Lminilibx-linux -lmlx ./LIBFT/libft.a -lXext -lX11 -lm -lz
else ifeq ($(UNAME_S),Darwin)
	# LDFLAGS = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit
	LDFLAGS = -Lmlx -lmlx -Imlx -L./LIBFT -lft -framework OpenGL -framework AppKit

else
	$(error Unsupported operating system: $(UNAME_S))
endif

AR = ar

ARFLAGS = rcs

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) all -C ./LIBFT
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
