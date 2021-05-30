/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:59:33 by keddib            #+#    #+#             */
/*   Updated: 2021/05/30 15:49:33 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	if (!src && !dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((char*)dst + i) = *((char*)src + i);
		i++;
	}
	return (dst);
}

int		*intdup(const int *src, size_t len)
{
	int *p;

	p = malloc(len * sizeof(int));
	ft_memcpy(p, src, len * sizeof(int));
	return (p);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*z;

	s = (unsigned char*)s1;
	z = (unsigned char*)s2;
	if (!s1 && !s2)
		return (0);
	i = 0;
	while (s[i] != '\0' || z[i] != '\0')
	{
		if (s[i] - z[i] != 0)
			return (s[i] - z[i]);
		i++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (s)
	{
		write(1, s, i);
	}
}
