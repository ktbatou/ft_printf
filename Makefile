# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 12:01:13 by ktbatou           #+#    #+#              #
#    Updated: 2019/11/01 14:52:03 by ktbatou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  printf.a
SRC = ft_printf.c conv_c.c conv_s.c main.c  libft/ft_putstr.c libft/ft_putchar.c libft/ft_strlen.c libft/ft_strnew.c
HDR = ft_printf.h

all : $(NAME)

$(NAME) :
	gcc  -c $(SRC) -I $(HDR)
	ar rc $(NAME) ft_printf.o conv_c.o conv_s.o main.o ft_putstr.o ft_putchar.o ft_strlen.o ft_strnew.o

clean :
		rm -f *.o
fclean : clean
		rm -f $(NAME)
re : fclean all
