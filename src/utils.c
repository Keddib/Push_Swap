/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:44:29 by keddib            #+#    #+#             */
/*   Updated: 2021/05/31 15:57:54 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_exit(void)
{
	write(2, "ERROR\n", 5);
	exit(1);
}

int	ft_isdigit(int c)
{
	if (c == 45)
		return (1);
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int	ft_isnum(const char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s))
			s++;
		else
			return (0);
	}
	return (1);
}

int	not_dup(t_data s, int i, int num)
{
	i++;
	while (i < s.size)
	{
		if (s.list[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str, int *valid)
{
	int	i;
	int	p;
	int	r;

	i = 0;
	p = 1;
	r = 0;
	*valid = ft_isnum(str);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r * p);
}
