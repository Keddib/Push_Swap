/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:54:38 by keddib            #+#    #+#             */
/*   Updated: 2021/05/31 16:08:21 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin(char *line, char buffer)
{
	char		*str;
	static int	i;

	if (!line[0])
		i = 0;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = buffer;
	str[i + 1] = '\0';
	free(line);
	i++;
	return (str);
}

int	get_next_line(char **line)
{
	int		n;
	char	buffer;

	*line = malloc(sizeof(1));
	if (!*line || !line)
		return (-1);
	**line = '\0';
	n = read(0, &buffer, 1);
	while (n == 1)
	{
		if (buffer == '\n')
			break ;
		*line = ft_strjoin(*line, buffer);
		if (*line == NULL)
			return (-1);
		n = read(0, &buffer, 1);
	}
	if (n == -1)
		free(line);
	return (n);
}
