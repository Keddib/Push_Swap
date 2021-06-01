/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:50:40 by keddib            #+#    #+#             */
/*   Updated: 2021/05/31 15:48:17 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	add_partition(t_data *d, int p)
{
	t_partition	*na;

	if (p)
	{
		na = ft_lstnew(d->pb->index[0], d->pb->index[0]);
		ft_lstadd_front(&d->pb, na);
	}
	else
	{
		na = ft_lstnew(d->pa->index[1], d->pa->index[1]);
		ft_lstadd_front(&d->pa, na);
	}
}

int	push(t_data *d, int a)
{
	if (a)
	{
		pb(d, 1);
		d->pa->index[1] -= 1;
		d->pb->index[0] -= 1;
	}
	else
	{
		pa(d, 1);
		d->pb->index[0] += 1;
		d->pa->index[1] += 1;
	}
	return (1);
}

void	three_numbers(t_data *d)
{
	if (d->list[0] > d->list[1] && d->list[1] < d->list[2]
		&& d->list[0] > d->list[2])
		ft_putstr("sa\n");
	else if (d->list[0] > d->list[1] && d->list[1] < d->list[2]
		&& d->list[2] > d->list[0])
		ft_putstr("ra\n");
	else if (d->list[0] < d->list[1] && d->list[1] > d->list[2]
		&& d->list[2] > d->list[0])
		ft_putstr("rra\n");
	else if (d->list[0] < d->list[1] && d->list[1] < d->list[2])
	{
		ft_putstr("sa\n");
		ft_putstr("rra\n");
	}
	else if (d->list[0] < d->list[1] && d->list[1] > d->list[2]
		&& d->list[0] > d->list[2])
	{
		ft_putstr("sa\n");
		ft_putstr("ra\n");
	}
}
