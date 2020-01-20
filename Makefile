# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 12:01:13 by ktbatou           #+#    #+#              #
#    Updated: 2020/01/20 20:13:53 by ktbatou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a

LIB = src/libft/ft_atoi.o	src/libft/ft_bzero.o   src/libft/ft_isalnum.o   src/libft/ft_isalpha.o \
	src/libft/ft_isascii.o	src/libft/ft_isdigit.o	src/libft/ft_isprint.o	 src/libft/ft_itoa.o\
	src/libft/ft_memalloc.o	src/libft/ft_memccpy.o	src/libft/ft_memchr.o	src/libft/ft_memcmp.o\
	src/libft/ft_memcpy.o	src/libft/ft_memdel.o	src/libft/ft_memmove.o	src/libft/ft_memset.o\
	src/libft/ft_putchar.o	src/libft/ft_putchar_fd.o	src/libft/ft_putendl.o	src/libft/ft_putendl_fd.o\
	src/libft/ft_putnbr.o	src/libft/ft_putnbr_fd.o	src/libft/ft_putstr.o	src/libft/ft_putstr_fd.o\
	src/libft/ft_strcat.o	src/libft/ft_strchr.o	src/libft/ft_strclr.o	src/libft/ft_strcmp.o\
	src/libft/ft_strcpy.o	src/libft/ft_strdel.o	src/libft/ft_strdup.o	src/libft/ft_strequ.o\
	src/libft/ft_striter.o	src/libft/ft_striteri.o	src/libft/ft_strnew.o	src/libft/ft_strlen.o\
	src/libft/ft_strjoin.o	src/libft/ft_strlcat.o	src/libft/ft_strmap.o	src/libft/ft_strncpy.o\
	src/libft/ft_strmapi.o	src/libft/ft_strncat.o	src/libft/ft_strncmp.o	src/libft/ft_strnequ.o\
	src/libft/ft_strnstr.o	src/libft/ft_strrchr.o	src/libft/ft_strsplit.o	src/libft/ft_strstr.o\
	src/libft/ft_strsub.o	src/libft/ft_strtrim.o	src/libft/ft_tolower.o	src/libft/ft_toupper.o

OBJ = ./src/print.o		./src/print_s.o		./src/xx_print.o		./src/negative_d_i.o \
	./src/o_print.o		./src/xx_types.o	./src/x_print.o		./src/o_types.o 	./src/x_types.o \
	./src/initial.o		./src/p_print.o		./src/u_print.o		./src/u_types.o		./src/int_types.o \
	./src/full_pre.o	./src/conv_s.o 		./src/conv_c.o		./src/ft_printf.o	./src/conv_p.o \
	./src/conv_x.o 		./src/conv_xx.o 	./src/conv_i.o		./src/conv_u.o		./src/ft_utoa.o \
	./src/conv_o.o 		./src/conv_d.o		./src/percent.o		./src/ft_ntoa.o \
	./src/ft_untoa.o	./src/ft_itoa_base.o 	./src/ft_nputstr.o $(LIB)

HDR = -I ./src/include -I ./src/libft

LIBFT = ./src/libft/libft.a

CFLAGS = $(HDR) -Wall -Wextra -Werror

CC = gcc

all : FA $(NAME)

$(NAME): $(OBJ)		
		ar rc $(NAME) $(OBJ)

FA :
	make -C ./src/libft

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)
re : fclean all
