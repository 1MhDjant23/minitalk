# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 17:41:03 by mait-taj          #+#    #+#              #
#    Updated: 2024/06/07 20:29:01 by mait-taj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_putstr.c	ft_printf.c	ft_putchar.c	ft_putnb.c	n_to_hexa.c	strchr_c.c	uns_to_dec.c	ft_putaddress.c\

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	@(ar rcs $(NAME) $(OBJS))

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean
