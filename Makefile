# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 11:44:42 by hadufer           #+#    #+#              #
#    Updated: 2021/10/08 07:35:19 by hadufer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g

SRCS =	draw_line.c \
		draw.c \
		draw2.c \
		key.c \
		main.c \
		mlx.c \
		read_file.c \
		util.c \
		util2.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I./Libftprintf/Libft -I./Libftprintf -Imlx_linux -c $< -o $@

$(NAME): $(OBJS) libftprintf
	$(CC) $(OBJS) -Lmlx_linux -l:libmlx_Linux.a -L./Libftprintf/ -l:libftprintf.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

libftprintf:
	$(MAKE) -C ./Libftprintf

clean:
	$(MAKE) -C ./Libftprintf $@
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ./Libftprintf $@
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean flcean re libftprintf
