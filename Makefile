#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 16:32:46 by ahjadani          #+#    #+#              #
#    Updated: 2021/12/31 14:05:21 by ahjadani         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = srcs
FILES = srcs/additional_funcs.c srcs/burningship.c srcs/fractol.c srcs/julia.c srcs/mandelbrot.c
CFLAGS = -Werror -Wextra -Wall
#XFLAGS = -I /usr/local/include -lmlx -framework OpenGL -framework AppKit

OBJECTS = $(FILES:.c=.o)
NAME = fractol
HEADER = include
CC = cc
RM = rm -f
UNAME = $(shell uname -s)
ifeq ($(UNAME),Linux)
	XFLAGS = -I /usr/local/include -lmlx -lXext -lX11 -lm
endif
ifeq ($(UNAME),Darwin)
	XFLAGS = -I /usr/local/include -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $^ -o $@ $(XFLAGS)

$(SRC)/%.o: $(SRC)/%.c $(HEADER)/fractol.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

bonus: all

startall:
	$(shell ./fractol Mandelbrot & ./fractol Julia & ./fractol "Burning ship")

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, startall, bonus
