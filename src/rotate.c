/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:01:10 by keddib            #+#    #+#             */
/*   Updated: 2021/05/29 19:52:54 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_data *s)
{
	if (s->sb > 1)
		rotate_right(s->list, s->sb);
	ft_putstr("ra\n");
}

void	rb(t_data *s)
{
	if (s->sb <= s->size - 2)
		rotate_left(s->list + s->sb, s->size - s->sb);
	ft_putstr("rb\n");
}

void	rr(t_data *s)
{
	if (s->sb > 1)
		rotate_right(s->list, s->sb);
	if (s->sb <= s->size - 2)
		rotate_left(s->list + s->sb, s->size - s->sb);
	ft_putstr("rr\n");
}
