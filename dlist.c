/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:33:21 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/02 14:51:21 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_llist	*newnode(void *data)
{
	t_llist	*tmp;

	tmp = malloc(sizeof(t_llist));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->next = NULL;
	tmp->previos = NULL;
	return (tmp);
}

t_llist	*add_back(t_llist **llist, t_llist *new)
{
	t_llist	*last;

	if (!new)
		return (NULL);
	new->next = NULL;
	if (!(*llist))
	{
		*llist = new;
		return (new);
	}
	new->previos = (*llist)->previos;
	if (!new->previos)
		new->previos = *llist;
	if ((*llist)->previos)
		(*llist)->previos->next = new;
	else
		(*llist)->next = new;
	
	(*llist)->previos = new;
	return (*llist);
}

t_llist	*add_front(t_llist **llist, t_llist *new)
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

void		*llist_clear(t_llist **llist, void (*del)(void *d))
{
	if (*llist)
		return (NULL);
	llist_clear(&((*llist)->next), del);
	del((*llist)->data);	
	free(*llist);
	*llist = NULL;
	return (NULL);
}

int			llist_size(t_llist *llist)
{
	int			size;

	if (!llist)
		return (0);
	size = 0;
	while (llist)
	{
		llist = llist->next;
		++size;
	}
	return (size);
}