# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keddib <keddib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 18:44:12 by keddib            #+#    #+#              #
#    Updated: 2021/06/01 20:36:59 by keddib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS				= push_swap

CHECKER			= checker

GCC				= gcc -Wall -Wextra -Werror

SRC				= src

SRCS			= push_swap.c						\
				push_swap_utils.c					\
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
				$(SRC)/get_next_line.c				\


all:	$(PS) $(CHECKER)

$(PS) : $(SRCS)
$(CHECKER) : $(CSRCS)
	@$(GCC) -o $(PS) $(SRCS)
	@$(GCC) -o $(CHECKER) $(CSRCS)

clean:
	@rm $(CHECKER) $(PS)

fclean: clean
	@rm -rf *.o *.dSYM

re: fclean all

.PHONY: clean fclean re all $(GNL)
