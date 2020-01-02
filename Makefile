# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/22 17:48:29 by ybouddou          #+#    #+#              #
#    Updated: 2019/12/30 20:20:26 by ybouddou         ###   ########.fr        #
#    Updated: 2019/12/30 20:07:30 by ybouddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = di_add_func.c \
	c_specifier.c \
	checkers_func.c \
	di_specifiers.c \
	ft_printf.c \
	func.c \
	add_func.c \
	additional_func.c \
	ft_printf.c \
	func.c \
	p_specifier.c \
	px_func.c \
	s_specifier.c \
	s_add_func.c \
	u_specifier.c \
	u_add_func.c \
	x_specifier.c \
	x_add_func.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
