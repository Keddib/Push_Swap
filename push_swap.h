/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:44:04 by keddib            #+#    #+#             */
/*   Updated: 2021/05/30 15:46:17 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_partition
{
	int					index[2];
	char				status;
	struct s_partition	*next;
}				t_partition;

typedef struct	s_data
{
	int			*list;
	int			*tmp;
	int			size;
	int			sb;
	t_partition	*pa;
	t_partition	*pb;
}				t_data;

int				get_next_line(int fd, char **line);
int				ft_atoi(const char *str, int *valid);
int				ft_isnum(const char *s);
int				ft_isdigit(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strlen(const char *s);
void			ft_putstr(char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
t_partition		*ft_lstnew(int f, int l);
void			ft_lstadd_front(t_partition **alst, t_partition *new);
void			ft_lstdelete_front(t_partition **alst);
int				ft_lstsize(t_partition *lst);
void			init_partitions(t_data *d);
int				*intdup(const int *src, size_t len);
void			delete_lst(t_partition **head_ref);
void			ft_exit(void);
int				not_dup(t_data s, int i, int num);
void			create_stack(t_data*s, int argc, char **argv);
void			swap(int *a, int *b);
void			rotate_right(int *arr, int size);
void			rotate_left(int *arr, int size);
int				is_sorted(t_data s);
void			bubble_sort(int *arr, int n);
int				is_p_sorted(int *l, t_partition *p);
void			free_data(t_data *d);
int				get_pivo(t_data d, int side, int *pd);
void			pb(t_data*s, int t);
void			pa(t_data*s, int t);
void			sa(t_data*s, int t);
void			sb(t_data*s, int t);
void			ss(t_data*s, int t);
void			ra(t_data*s, int t);
void			rb(t_data*s, int t);
void			rr(t_data*s, int t);
void			rra(t_data*s, int t);
void			rrb(t_data*s, int t);
void			rrr(t_data*s, int t);

#endif
