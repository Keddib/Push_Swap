/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:52:29 by keddib            #+#    #+#             */
/*   Updated: 2021/05/29 19:02:43 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void		pb(t_data *s)
{
	if (s->sb > 0)
		s->sb--;
	ft_putstr("pb\n");
}

void		pa(t_data *s)
{
	if (s->sb < s->size)
		s->sb++;
	ft_putstr("pa\n");
}

void		sa(t_data *s)
{
	if (s->sb >= 2)
		swap(&s->list[s->sb - 1], &s->list[s->sb - 2]);
	ft_putstr("sa\n");
}

void		sb(t_data *s)
{
	if (s->sb <= s->size - 2)
		swap(&s->list[s->sb], &s->list[s->sb + 1]);
	ft_putstr("sb\n");
}

void		ss(t_data *s)
{
	if (s->sb >= 2)
		swap(&s->list[s->sb - 1], &s->list[s->sb - 2]);
	if (s->sb <= s->size - 2)
		swap(&s->list[s->sb], &s->list[s->sb + 1]);
	ft_putstr("ss\n");
}
