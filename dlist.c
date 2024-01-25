/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:33:21 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/25 23:26:34 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_dllist	*newnode(void *data)
{
	t_dllist	*tmp;

	tmp = malloc(sizeof(t_dllist));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->next = NULL;
	tmp->previos = NULL;
	return (tmp);
}

t_dllist	*add_back(t_dllist **llist, t_dllist *new)
{
	if (!new)
		return (NULL);
	if (!(*llist))
	{
		*llist = new;
		return (new);
	}
	new->next = llist;
	new->previos = (*llist)->previos;
	(*llist)->previos->next = new;
	return (llist);
}

t_dllist	*add_front(t_dllist **llist, t_dllist *new)
{
	if (!new)
		return (NULL);
	if (!(*llist))
	{
		*llist = new;
		return (new);
	}
	new->next = *llist;
	new->previos = (*llist)->previos;
	(*llist)->previos->next = new;
	(*llist)->previos = new;
	*llist = new;
	return (*llist);
}

void		*llist_clear(t_dllist **llist, t_dllist *f, void (*del)(void *d))
{
	
	if (*llist == f)
		return (NULL);
	llist_clear(&((*llist)->next), f, del);
	del((*llist)->data);	
	free(*llist);
	*llist = NULL;
	return (NULL);
}

int			*llist_size(t_dllist *llist, t_dllist *f)
{
	int	size;

	size = 0;
	while (llist != f)
	{
		llist = llist->next;
		++size;
	}
	return (size);
}