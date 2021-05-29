/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:55:14 by keddib            #+#    #+#             */
/*   Updated: 2021/05/29 20:02:32 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		is_p_sorted(int *l, t_partition *p)
{
	int		*tmp;
	int		size;
	int		i;

	size = p->index[1] - p->index[0];
	tmp = l + p->index[0];
	i = 0;
	if (size == 1)
	{
		p->status = 's';
		return (1);
	}
	while (i < size)
	{
		if (tmp[i] > tmp[i + 1])
			i++;
		else
			return (0);
	}
	p->status = 's';
	return (1);
}

void	bubble_sort(int *arr, int n)
{
	int i;
	int j;
	int swp;

	i = 0;
	while (i < n)
	{
		j = 0;
		swp = 0;
		while (j < n - i - 1)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swp = 1;
			}
			j++;
		}
		if (swp == 0)
			return ;
		i++;
	}
}
