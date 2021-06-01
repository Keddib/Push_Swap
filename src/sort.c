/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:55:14 by keddib            #+#    #+#             */
/*   Updated: 2021/05/31 15:40:28 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_p_sorted(int *l, t_partition *p)
{
	int		*tmp;
	int		size;
	int		i;

	size = p->index[1] - p->index[0];
	tmp = l + p->index[0];
	i = 0;
	if (size == 1)
	{
		p->s = 's';
		return (1);
	}
	while (i < size - 1)
	{
		if (tmp[i] > tmp[i + 1])
			i++;
		else
			return (0);
	}
	p->s = 's';
	return (1);
}

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	swp;

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

void	init_partitions(t_data *d)
{
	d->pa = ft_lstnew(0, d->sb);
	d->pb = ft_lstnew(d->sb, d->sb);
}

void	free_data(t_data *d)
{
	free(d->list);
	free(d->tmp);
	delete_lst(&d->pa);
	delete_lst(&d->pb);
}

int	get_pivo(t_data d, int side, int *pd)
{
	int	size;
	int	*arr;

	if (side)
	{
		arr = d.tmp + d.pb->index[0];
		size = d.pb->index[1] - d.pb->index[0];
		*pd = size / 2;
		return (arr[size / 2]);
	}
	else
	{
		arr = d.tmp + d.pa->index[0];
		size = d.pa->index[1] - d.pa->index[0];
		if (size % 2 == 0)
		{
			*pd = (size / 2);
			return (arr[(size / 2) - 1]);
		}
	}
	*pd = size / 2;
	return (arr[size / 2]);
}
