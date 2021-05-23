#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_stack
{
	int *list;
	int size;
	int sb;
}				stack;

int				ft_atoi(const char *str);

#endif
