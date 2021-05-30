/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:43:46 by keddib            #+#    #+#             */
/*   Updated: 2021/05/30 14:01:25 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	B_to_A_direct(t_data*d)
{
	int i = 0;
	while (i < d->pb->index[1] - d->pb->index[0])
	{
		pa(d, 1);
		d->pa->index[1] += 1;
		i++;
	}
	ft_lstdelete_front(&d->pb);
}

void	B_to_A(t_data*d)
{
	int			p;
	int			pd;
	int			rotate;
	t_partition	*na;

	rotate = 0;
	is_p_sorted(d->list, d->pb);
	if (d->pb->status == 'n' && (d->pb->index[1] - d->pb->index[0]) == 2)
	{
		sb(d, 1);
		d->pb->status = 's';
	}
	else if (d->pb->status == 's')
	{
		na = ft_lstnew(d->pa->index[1], d->pa->index[1]);
		ft_lstadd_front(&d->pa, na);
		B_to_A_direct(d);
	}
	else
	{
		na = ft_lstnew(d->pa->index[1], d->pa->index[1]);
		ft_lstadd_front(&d->pa, na);
		p = get_pivo(*d, 1, &pd);
		while (pd > 0)
		{
			if (d->list[d->sb] > p)
			{
				pa(d, 1);
				d->pb->index[0] += 1;
				d->pa->index[1] += 1;
				pd--;
			}
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
}

void	A_to_B(t_data*d)
{
	int			p;
	int			pd;
	int			rotate;
	t_partition	*na;

	rotate = 0;
	p = get_pivo(*d, 0, &pd);
	if (d->pb->index[0] != d->pb->index[1])
	{
		na = ft_lstnew(d->pb->index[0], d->pb->index[0]);
		ft_lstadd_front(&d->pb, na);
	}
	while (pd > 0)
	{
		if (d->list[d->sb -1] < p)
		{
			pb(d, 1);
			d->pa->index[1] -= 1;
			d->pb->index[0] -= 1;
			pd--;
		}
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

void	quick_sort(t_data*d)
{
	while (1)
	{
		if (is_sorted(*d))
			break;
		else if (is_p_sorted(d->list, d->pa))
			B_to_A(d);
		else
		{
			if (d->pa->index[1] - d->pa->index[0] == 2)
			{
				sa(d, 1);
				d->pa->status = 's';
			}
			else
				A_to_B(d);
		}
	}
}

void	three_numbers(t_data *d)
{
	if (d->list[0] > d->list[1] && d->list[1] < d->list[2] &&
	d->list[0] > d->list[2])
		ft_putstr("sa\n");
	else if (d->list[0] > d->list[1] && d->list[1] < d->list[2] &&
	d->list[2] > d->list[0])
		ft_putstr("ra\n");
	else if (d->list[0] < d->list[1] && d->list[1] > d->list[2] &&
	d->list[2] > d->list[0])
		ft_putstr("rra\n");
	else if (d->list[0] < d->list[1] && d->list[1] < d->list[2])
	{
		ft_putstr("sa\n");
		ft_putstr("rra\n");
	}
	else if (d->list[0] < d->list[1] && d->list[1] > d->list[2] &&
	d->list[0] > d->list[2])
	{
		ft_putstr("sa\n");
		ft_putstr("ra\n");
	}
}

int main(int argc, char **argv)
{
	t_data data;

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
	return 0;
}
