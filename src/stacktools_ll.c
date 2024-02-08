/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacktools_ll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:33:17 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/08 13:37:37 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_ll(t_llist **dest, t_llist **src)
{
	t_llist	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	if ((*src)->next)
		(*src)->next->previos = (*src)->previos;
	*src = (*src)->next;
	if (!(*dest))
	{
		tmp->next = NULL;
		tmp->previos = tmp;
		*dest = tmp;
		return ;
	}
	tmp->next = *dest;
	tmp->previos = (*dest)->previos;
	(*dest)->previos = tmp;
	*dest = tmp;
}

void	rotate_ll(t_llist **llist)
{
	if (!(*llist) || !(*llist)->next)
		return ;
	(*llist)->previos->next = *llist;
	*llist = (*llist)->next;
	(*llist)->previos->next = NULL;
}

void	rev_rotate_ll(t_llist **llist)
{
	if (!(*llist) || !(*llist)->next)
		return ;
	(*llist)->previos->next = *llist;
	*llist  = (*llist)->previos;
	(*llist)->previos->next = NULL;
}

void	swap_ll(t_llist *llist)
{
	t_llist	tmp;

	if (!llist || !llist->next)
		return ;
	if (llist_size(llist) < 2)
		return ;
	tmp.data = llist->data;
	llist->data = llist->next->data;
	llist->next->data = tmp.data;
}

