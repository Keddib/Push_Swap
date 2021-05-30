/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:43:00 by keddib            #+#    #+#             */
/*   Updated: 2021/05/30 17:43:13 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	do_operations(t_data *d, char *buff)
{
	if (ft_strcmp(buff, "sa") == 0)
		sa(d, 0);
	else if (ft_strcmp(buff, "sb") == 0)
		sb(d, 0);
	else if (ft_strcmp(buff, "ss") == 0)
		ss(d, 0);
	else if (ft_strcmp(buff, "pa") == 0)
		pa(d, 0);
	else if (ft_strcmp(buff, "pb") == 0)
		pb(d, 0);
	else if (ft_strcmp(buff, "ra") == 0)
		ra(d, 0);
	else if (ft_strcmp(buff, "rb") == 0)
		rb(d, 0);
	else if (ft_strcmp(buff, "rr") == 0)
		rr(d, 0);
	else if (ft_strcmp(buff, "rra") == 0)
		rra(d, 0);
	else if (ft_strcmp(buff, "rrb") == 0)
		rrb(d, 0);
	else if (ft_strcmp(buff, "rrr") == 0)
		rrr(d, 0);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	d;
	char	*buff;

	if (argc == 1)
		return (0);
	create_stack(&d, argc, argv);
	while (get_next_line(0, &buff))
	{
		if (do_operations(&d, buff))
			continue;
		else
			ft_exit();
	}
	if (buff[0])
		ft_exit();
	if (is_sorted(d))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_data(&d);
	return (0);
}
