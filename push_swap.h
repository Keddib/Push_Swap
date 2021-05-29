#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


typedef struct	s_partition
{
	int			index[2];
	char		status;
	struct		s_partition *next;
}				t_partition;


typedef struct	s_data
{
	int			*list;
	int			*tmp;
	int			size;
	int			sb;
	t_partition	*PA;
	t_partition *PB;
}				data;

int				ft_atoi(const char *str, int *valid);
int				ft_isnum(const char *s);
int				ft_isdigit(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				*intdup(const int *src, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
t_partition		*ft_lstnew(int f, int l);
void			ft_lstadd_front(t_partition **alst, t_partition *new);
void			ft_lstdelete_front(t_partition **alst);
int				ft_lstsize(t_partition *lst);
void			ft_exit(void);
int				not_dup(data s, int i, int num);
void			create_stack(data *s, int argc, char **argv);
void			print_stack(data s);
void			swap(int *a, int *b);
void			rotate_right(int *arr, int size);
void			rotate_left(int *arr, int size);
int				is_sorted(data s);
void			bubble_sort(int *arr, int n);
int				is_p_sorted(int *l, t_partition *p);
void			pb(data *s);
void			pa(data *s);
void			sa(data *s);
void			sb(data *s);
void			ss(data *s);
void			ra(data *s);
void			rb(data *s);
void			rr(data *s);
void			rra(data *s);
void			rrb(data *s);
void			rrr(data *s);

void	print_array(int *arr, int size);

#endif
