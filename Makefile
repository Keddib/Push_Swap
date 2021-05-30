# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keddib <keddib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 18:44:12 by keddib            #+#    #+#              #
#    Updated: 2021/05/30 15:47:14 by keddib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS				= push_swap

CHECKER			= checker

GCC				= gcc -Wall -Wextra -Werror

SRC				= src

GNL				= gn_line/get_next_line.c gn_line/get_next_line_utils.c

SRCS			= push_swap.c						\
				$(SRC)/stack.c						\
				$(SRC)/utils.c						\
				$(SRC)/utils_2.c					\
				$(SRC)/swap_push.c					\
				$(SRC)/rotate.c						\
				$(SRC)/rrotate.c					\
				$(SRC)/linkedlist.c					\
				$(SRC)/sort.c						\

CSRCS			= checker.c							\
				$(SRC)/stack.c						\
				$(SRC)/utils.c						\
				$(SRC)/utils_2.c					\
				$(SRC)/swap_push.c					\
				$(SRC)/rotate.c						\
				$(SRC)/rrotate.c					\
				$(SRC)/linkedlist.c					\
				$(SRC)/sort.c						\

GNL				= ./gn_line

all:	$(GNL) $(PS) $(CHECKER)

$(PS) : $(SRCS)
$(CHECKER) : $(CSRCS)
	$(GCC) -o $(PS) $(SRCS) gnl.a
	$(GCC) -o $(CHECKER) $(CSRCS) gnl.a

$(GNL):
	$(MAKE) -C $@

clean:
	rm $(CHECKER) $(PS) gnl.a

fclean: clean
	rm -rf *.o *.dSYM

re: fclean all

.PHONY: clean fclean re all $(GNL)
