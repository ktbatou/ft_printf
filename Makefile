# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 12:01:13 by ktbatou           #+#    #+#              #
#    Updated: 2019/12/26 14:17:08 by ktbatou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
SRC = print.c print_s.c xx_print.c o_print.c xx_types.c x_print.c o_types.c x_types.c initial.c p_print.c u_print.c u_types.c int_types.c full_pre.c conv_s.c conv_c.c ft_printf.c conv_p.c conv_x.c conv_xx.c  conv_i.c conv_u.c ft_utoa.c conv_o.c percent.c conv_d.c percent.c ft_ntoa.c ft_untoa.c ft_itoa_base.c ft_nputstr.c $(libft/libft.a)
HDR = ./ft_printf.h
OBJ = 
FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc $(FLAG) -g -c $(SRC)
	ar rc $(NAME) *.o libft/*.o

clean :
		rm -f *.o
fclean : clean
		rm -f $(NAME)
re : fclean all
