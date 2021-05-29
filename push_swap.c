/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:43:46 by keddib            #+#    #+#             */
/*   Updated: 2021/05/29 18:48:23 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void		init_partitions(t_data *d)
{
	d->PA = ft_lstnew(0, d->sb);
	d->PB = ft_lstnew(d->sb, d->sb);
}

void	free_data(t_data *d)
{
	free(d->list);
	free(d->tmp);
	delete_lst(&d->PA);
	delete_lst(&d->PB);
}

int		get_pivo(t_data d, int side, int *pd)
{
	int size;
	int *arr;

	if (side)
	{
		arr = d.tmp + d.PB->index[0];
		size = d.PB->index[1] - d.PB->index[0];
		*pd = size / 2;
		return (arr[size / 2]);
	}
	else
	{
		arr = d.tmp + d.PA->index[0];
		size = d.PA->index[1] - d.PA->index[0];
		if (size % 2 == 0)
		{
			*pd = (size / 2);
			return (arr[(size / 2) - 1]);
		}
	}
	*pd = size / 2;
	return (arr[size / 2]);
}

void	B_to_A_direct(t_data*d)
{
	int i = 0;
	while (i < d->PB->index[1] - d->PB->index[0])
	{
		pa(d);
		d->PA->index[1] += 1;
		i++;
	}
	ft_lstdelete_front(&d->PB);
}

void	B_to_A(t_data*d)
{
	int p;
	int pd;
	t_partition *na;
	int rotate = 0;
	is_p_sorted(d->list, d->PB);
	if (d->PB->status == 'n' && (d->PB->index[1] - d->PB->index[0]) == 2)
	{
		sb(d);
		d->PB->status = 's';
	}
	else if (d->PB->status == 's')
	{
		na = ft_lstnew(d->PA->index[1], d->PA->index[1]);
		ft_lstadd_front(&d->PA, na);
		B_to_A_direct(d);
	}
	else
	{
		na = ft_lstnew(d->PA->index[1], d->PA->index[1]);
		ft_lstadd_front(&d->PA, na);
		p = get_pivo(*d, 1, &pd);
		while (pd > 0)
		{
			if (d->list[d->sb] > p)
			{
				pa(d);
				d->PB->index[0] += 1;
				d->PA->index[1] += 1;
				pd--;
			}
			else
			{
				rb(d);
				if (d->PB->next)
					rotate++;
			}
		}
		while (rotate--)
			rrb(d);
	}
}

void	A_to_B(t_data*d)
{
	int p;
	int pd;
	t_partition *na;
	int rotate = 0;
	p = get_pivo(*d, 0, &pd);
	if (d->PB->index[0] != d->PB->index[1])
	{
		na = ft_lstnew(d->PB->index[0], d->PB->index[0]);
		ft_lstadd_front(&d->PB, na);
	}
	while (pd > 0)
	{
		if (d->list[d->sb -1] < p)
		{
			pb(d);
			d->PA->index[1] -= 1;
			d->PB->index[0] -= 1;
			pd--;
		}
		else
		{
			if (d->PA->next)
				rotate++;
			ra(d);
		}
	}
	while (rotate--)
		rra(d);
}

void	quick_sort(t_data*d)
{
	while (1)
	{
		if (is_sorted(*d))
			break;
		else if (is_p_sorted(d->list, d->PA))
			B_to_A(d);
		else
		{
			if (d->PA->index[1] - d->PA->index[0] == 2)
			{
				sa(d);
				d->PA->status = 's';
			}
			else
				A_to_B(d);
		}
	}
}



int main(int argc, char **argv)
{
	t_data data;

	if (argc == 1)
		return (0);
	create_stack(&data, argc, argv);
	data.tmp = intdup(data.list, data.size);
	init_partitions(&data);
	bubble_sort(data.tmp, data.size);
	quick_sort(&data);
	free_data(&data);
	return 0;
}
