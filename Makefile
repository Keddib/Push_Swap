NAME			= push_swap

GCC				= gcc -Wall -Wextra -Werror

SRC				= src

SRCS			= push_swap.c							\
				$(SRC)/stack.c						\
				$(SRC)/utils.c						\
				$(SRC)/operations.c					\



all:	$(NAME)


$(NAME) : $(SRCS)
	$(GCC) -o $(NAME) $(SRCS)

clean:
	rm $(NAME)

fclean: clean
	rm -rf *.o *.dSYM

re: fclean all

.PHONY: clean fclean re all
