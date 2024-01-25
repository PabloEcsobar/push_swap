/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:48:02 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/25 23:30:35 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	rev_rotate_ll(t_dllist **llist)
{
	if (!(*llist) || !(*llist)->next)
		return ;
	*llist  = (*llist)->previos;
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
