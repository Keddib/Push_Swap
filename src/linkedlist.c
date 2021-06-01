/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:43:57 by keddib            #+#    #+#             */
/*   Updated: 2021/05/31 16:08:50 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	delete_lst(t_partition **head_ref)
{
	t_partition	*current;
	t_partition	*next;

	current = *head_ref;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head_ref = NULL;
}

t_partition	*ft_lstnew(int f, int l)
{
	t_partition	*p;

	p = malloc(sizeof(t_partition));
	if (!p)
		return (NULL);
	p->index[0] = f;
	p->index[1] = l;
	p->s = 'n';
	p->next = NULL;
	return (p);
}

void	ft_lstadd_front(t_partition **alst, t_partition *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_lstdelete_front(t_partition **alst)
{
	t_partition	*todelete;

	todelete = *alst;
	*alst = (*alst)->next;
	free(todelete);
}

int	ft_lstsize(t_partition *lst)
{
	t_partition	*head;
	int			count;

	head = lst;
	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}
