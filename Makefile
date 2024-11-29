# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 10:15:33 by oobbad            #+#    #+#              #
#    Updated: 2024/11/29 11:09:37 by oobbad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putnbr.c ft_putstr.c ft_puthex.c ft_putchar.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $@ $(OBJ)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
