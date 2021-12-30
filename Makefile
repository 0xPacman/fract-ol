#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 16:32:46 by ahjadani          #+#    #+#              #
#    Updated: 2021/12/30 17:20:41 by ahjadani         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = srcs
FILES = srcs/additional_funcs.c srcs/burningship.c srcs/fractol.c srcs/julia.c srcs/mandelbrot.c
CFLAGS = -Werror -Wextra -Wall
XFLAGS = -I /usr/local/include -lmlx -framework OpenGL -framework AppKit
OBJECTS = $(FILES:.c=.o)
HEADER = inlcude
NAME = fractol
CC = cc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $^ -o $@ $(XFLAGS)

$(SRC)/%.o: $(SRC)/%.c $(HEADER)/fractol.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

bonus: all

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
