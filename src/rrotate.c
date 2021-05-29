/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:00:24 by keddib            #+#    #+#             */
/*   Updated: 2021/05/29 19:52:59 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_data *s)
{
	if (s->sb > 1)
		rotate_left(s->list, s->sb);
	ft_putstr("rra\n");
}

void	rrb(t_data *s)
{
	if (s->sb <= s->size - 2)
		rotate_right(s->list + s->sb, s->size - s->sb);
	ft_putstr("rrb\n");
}

void	rrr(t_data *s)
{
	if (s->sb > 1)
		rotate_left(s->list, s->sb);
	if (s->sb <= s->size - 2)
		rotate_right(s->list + s->sb, s->size - s->sb);
	ft_putstr("rrr\n");
}
