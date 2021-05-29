# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keddib <keddib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 18:44:12 by keddib            #+#    #+#              #
#    Updated: 2021/05/29 20:03:28 by keddib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

GCC				= gcc -Wall -Wextra -Werror

SRC				= src

SRCS			= push_swap.c						\
				$(SRC)/stack.c						\
				$(SRC)/utils.c						\
				$(SRC)/utils_2.c					\
				$(SRC)/swap_push.c					\
				$(SRC)/rotate.c						\
				$(SRC)/rrotate.c					\
				$(SRC)/linkedlist.c					\
				$(SRC)/sort.c						\



all:	$(NAME)


$(NAME) : $(SRCS)
	$(GCC) -o $(NAME) $(SRCS)

clean:
	rm $(NAME)

fclean: clean
	rm -rf *.o *.dSYM

re: fclean all

.PHONY: clean fclean re all
