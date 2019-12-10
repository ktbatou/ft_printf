# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktbatou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 11:38:26 by ktbatou           #+#    #+#              #
#    Updated: 2019/12/09 19:12:44 by ktbatou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ./*.c
HEADER = ./*.h

all : $(NAME)

$(NAME) :
	gcc -g -Wextra -Werror -Wall -c $(SRC) -I $(HEADER)
	ar rc $(NAME) ./*.o
clean :
	rm -f *.o
fclean : clean
	rm -f $(NAME)
re : fclean all
