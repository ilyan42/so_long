# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:49:42 by ilbendib          #+#    #+#              #
#    Updated: 2023/12/07 11:22:37 by ilyanbendib      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _SRCS = main.c

# SRC_DIR = .

# SRCS = $(_SRCS:%=$(SRC_DIR)/%)

# _HEADERS = so_long.h

# HEADERS_DIR = .

# HEADERS = $(_HEADERS:%=$(HEADERS_DIR)/%)

# CC = gcc

# CFLAGS = -Wall -Wextra -Werror

# LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
# #LDFLAGS = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit

# AR = ar

# ARFLAGS = rcs

# OBJS = $(SRCS:.c=.o)

# NAME = so_long

# all: $(NAME)

# %.o: %.c $(HEADERS)
# 	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re

_SRCS = main.c

SRC_DIR = .

SRCS = $(_SRCS:%=$(SRC_DIR)/%)

_HEADERS = so_long.h

HEADERS_DIR = .

HEADERS = $(_HEADERS:%=$(HEADERS_DIR)/%)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
else ifeq ($(UNAME_S),Darwin)
	LDFLAGS = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit
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
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
