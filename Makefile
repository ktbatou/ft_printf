# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 12:01:13 by ktbatou           #+#    #+#              #
#    Updated: 2019/12/09 16:47:13 by ktbatou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
SRC = print.c full_pre.c conv_s.c conv_c.c ft_printf.c conv_p.c conv_x.c conv_xx.c  conv_i.c conv_u.c ft_utoa.c conv_o.c percent.c conv_d.c percent.c ft_ntoa.c ft_untoa.c ft_itoa_base.c ft_nputstr.c $(libft/libft.a)
HDR = ./ft_printf.h

all : $(NAME)

$(NAME) :
	gcc  -g -c $(SRC) #-I $(HDR)
	ar rc $(NAME) *.o libft/*.o

clean :
		rm -f *.o
fclean : clean
		rm -f $(NAME)
re : fclean all
