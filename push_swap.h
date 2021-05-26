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
	int tmp;
}				stack;

int				ft_atoi(const char *str, int *valid);
int				ft_isnum(const char *s);
int				ft_isdigit(int c);
int				not_dup(stack s, int i, int num);
void			ft_exit(void);
void			create_stack(stack *s, int argc, char **argv);
void			print_stack(stack s);
void			swap(int *a, int *b);
void			rotate_right(int *arr, int size);
void			rotate_left(int *arr, int size);
int				is_sorted(stack s);
void			pb(stack *s);
void			pa(stack *s);
void			sa(stack *s);
void			sb(stack *s);
void			ss(stack *s);
void			ra(stack *s);
void			rb(stack *s);
void			rr(stack *s);
void			rra(stack *s);
void			rrb(stack *s);
void			rrr(stack *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			bubble_sort(int *arr, int n);
int				*intdup(const int *src, size_t len);

#endif
