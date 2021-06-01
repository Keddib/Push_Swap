/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:44:20 by keddib            #+#    #+#             */
/*   Updated: 2021/05/31 16:10:44 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_data s)
{
	int	i;

	i = 0;
	if (s.sb < s.size)
		return (0);
	while (i < s.size - 1)
	{
		if (s.list[i] > s.list[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	rotate_right(int *arr, int size)
{
	int	j;
	int	last;

	last = arr[size - 1];
	j = size - 1;
	while (j > 0)
	{
		arr[j] = arr[j - 1];
		j--;
	}
	arr[0] = last;
}

void	rotate_left(int *arr, int size)
{
	int	j;
	int	first;

	first = arr[0];
	j = 0;
	while (j < size - 1)
	{
		arr[j] = arr[j + 1];
		j++;
	}
	arr[j] = first;
}

void	create_stack(t_data *s, int argc, char **argv)
{
	int	i;
	int	valid;
	int	num;

	s->size = argc - 1;
	s->sb = s->size;
	s->list = (int *)malloc(s->size * sizeof(int));
	if (!s->list)
		ft_exit();
	i = s->size - 1;
	argv++;
	while (*argv)
	{
		num = ft_atoi(*argv, &valid);
		if (valid && not_dup(*s, i, num) && ft_strcmp(*argv, "-") != 0)
			s->list[i] = num;
		else
			ft_exit();
		argv++;
		i--;
	}
}
