/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:43:46 by keddib            #+#    #+#             */
/*   Updated: 2021/06/01 20:27:07 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	b_to_a_direct(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->pb->index[1] - d->pb->index[0])
	{
		pa(d, 1);
		d->pa->index[1] += 1;
		i++;
	}
	ft_lstdelete_front(&d->pb);
	return (1);
}

void	b_to_a(t_data *d)
{
	int			p;
	int			pd;
	int			rotate;

	rotate = 0;
	if (d->pb->s == 's' && b_to_a_direct(d))
		return ;
	add_partition(d, 0);
	p = get_pivo(*d, 1, &pd);
	while (pd > 0)
	{
		if (d->pb->next == NULL)
		{
			if (d->list[d->size - 1] > p)
				if (d->list[d->sb] > d->list[d->size - 1])
					rrb(d, 1);
		}
		if (d->list[d->sb] > p && push(d, 0))
			pd--;
		else
		{
			rb(d, 1);
			if (d->pb->next)
				rotate++;
		}
	}
	while (rotate--)
		rrb(d, 1);
}

void	a_to_b(t_data *d)
{
	int			p;
	int			pd;
	int			rotate;

	rotate = 0;
	p = get_pivo(*d, 0, &pd);
	if (d->pb->index[0] != d->pb->index[1])
		add_partition(d, 1);
	while (pd > 0)
	{
		if (d->pa->next == NULL)
		{
			if (d->list[0] < p)
				if (d->list[0] < d->list[d->sb - 1])
					rra(d, 1);
		}
		if (d->list[d->sb - 1] < p && push(d, 1))
			pd--;
		else
		{
			if (d->pa->next)
				rotate++;
			ra(d, 1);
		}
	}
	while (rotate--)
		rra(d, 1);
}

void	quick_sort(t_data *d)
{
	while (1)
	{
		if (is_sorted(*d))
			break ;
		else if (is_p_sorted(d->list, d->pa))
		{
			is_p_sorted(d->list, d->pb);
			if (d->pb->s == 'n' && (d->pb->index[1] - d->pb->index[0]) == 2)
			{
				sb(d, 1);
				d->pb->s = 's';
			}
			b_to_a(d);
		}
		else
		{
			if (d->pa->index[1] - d->pa->index[0] == 2)
			{
				sa(d, 1);
				d->pa->s = 's';
			}
			else
				a_to_b(d);
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (0);
	else
	{
		create_stack(&data, argc, argv);
		data.tmp = intdup(data.list, data.size);
		if (argc == 4)
			three_numbers(&data);
		else
		{
			init_partitions(&data);
			bubble_sort(data.tmp, data.size);
			quick_sort(&data);
		}
		free_data(&data);
	}
	return (0);
}
