/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:48:02 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/02 14:51:38 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	rev_rotate_ll(t_llist **llist)
{
	if (!(*llist) || !(*llist)->next)
		return ;
	(*llist)->previos->next = *llist;
	*llist  = (*llist)->previos;
	(*llist)->previos->next = NULL;
}

void	rev_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next->next)
		last = last->next;
	first = last->next;
	first->next = *stack;
	*stack = first;
	last->next = NULL;
}

char	*rev_rotate_a(t_list **stack)
{
	rev_rotate(stack);
	return (ft_strdup(RRA));
}

char	*rev_rotate_b(t_list **stack)
{
	rev_rotate(stack);
	return (ft_strdup(RRB));
}

char	*rev_rotate_all(t_llist **llist)
{
	rev_rotate_ll(llist);
	return (ft_strdup(RRA));
}

char	*rev_rotate_bll(t_llist **llist)
{
	rev_rotate_ll(llist);
	return (ft_strdup(RRB));
}
