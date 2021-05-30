/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:01:10 by keddib            #+#    #+#             */
/*   Updated: 2021/05/30 13:29:01 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_data *s, int t)
{
	if (s->sb > 1)
		rotate_right(s->list, s->sb);
	if (t)
		ft_putstr("ra\n");
}

void	rb(t_data *s, int t)
{
	if (s->sb <= s->size - 2)
		rotate_left(s->list + s->sb, s->size - s->sb);
	if (t)
		ft_putstr("rb\n");
}

void	rr(t_data *s, int t)
{
	if (s->sb > 1)
		rotate_right(s->list, s->sb);
	if (s->sb <= s->size - 2)
		rotate_left(s->list + s->sb, s->size - s->sb);
	if (t)
		ft_putstr("rr\n");
}
