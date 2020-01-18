# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 12:01:13 by ktbatou           #+#    #+#              #
#    Updated: 2020/01/16 20:41:25 by ktbatou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a

SRC = ./src/print.c		./src/print_s.c		./src/xx_print.c		./src/negative_d_i.c \
	./src/o_print.c		./src/xx_types.c	./src/x_print.c		./src/o_types.c 	./src/x_types.c \
	./src/initial.c		./src/p_print.c		./src/u_print.c		./src/u_types.c		./src/int_types.c \
	./src/full_pre.c	./src/conv_s.c 		./src/conv_c.c		./src/ft_printf.c	./src/conv_p.c \
	./src/conv_x.c 		./src/conv_xx.c 	./src/conv_i.c		./src/conv_u.c		./src/ft_utoa.c \
	./src/conv_o.c 		./src/percent.c		./src/conv_d.c		./src/percent.c		./src/ft_ntoa.c \
	./src/ft_untoa.c	./src/ft_itoa_base.c 	./src/ft_nputstr.c

 OBJ = $(SRC:.c=.o)
#  ./src/print.o		./src/print_s.o		./src/xx_print.o		./src/negative_d_i.o \
# 	./src/o_print.o		./src/xx_types.o	./src/x_print.o		./src/o_types.o 	./src/x_types.o \
# 	./src/initial.o		./src/p_print.o		./src/u_print.o		./src/u_types.o		./src/int_types.o \
# 	./src/full_pre.o	./src/conv_s.o 		./src/conv_c.o		./src/ft_printf.o	./src/conv_p.o \
# 	./src/conv_x.o		./src/conv_xx.o 	./src/conv_i.o		./src/conv_u.o		./src/ft_utoa.o \
# 	./src/conv_o.o 		./src/percent.o		./src/conv_d.o		./src/percent.o		./src/ft_ntoa.o \
# 	./src/ft_untoa.o	./src/ft_itoa_base.o 	./src/ft_nputstr.o

HDR = ./src/include/ft_printf.h

LIBFT = -include ./src/libft/libft.a

FLAG = -Wall -Wextra -Werror

all : $(OBJ)

$(OBJ): ./src/%.o : ./src/%.c
	gcc $(FLAGS) $< -o $@ -I ./src/include -I ./src/libft
	ar rc $(NAME) $(OBJ) ./src/libft/*.o

clean :
		rm -f $(OBJ)
fclean : clean
		rm -f $(NAME)
re : fclean all
