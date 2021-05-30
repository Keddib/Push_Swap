/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:00:24 by keddib            #+#    #+#             */
/*   Updated: 2021/05/30 13:29:23 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_data *s, int t)
{
	if (s->sb > 1)
		rotate_left(s->list, s->sb);
	if (t)
		ft_putstr("rra\n");
}

void	rrb(t_data *s, int t)
{
	if (s->sb <= s->size - 2)
		rotate_right(s->list + s->sb, s->size - s->sb);
	if (t)
		ft_putstr("rrb\n");
}

void	rrr(t_data *s, int t)
{
	if (s->sb > 1)
		rotate_left(s->list, s->sb);
	if (s->sb <= s->size - 2)
		rotate_right(s->list + s->sb, s->size - s->sb);
	if (t)
		ft_putstr("rrr\n");
}
