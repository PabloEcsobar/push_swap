/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:44:48 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/02 14:51:29 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	rotate_ll(t_llist **llist)
{
	if (!(*llist) || !(*llist)->next)
		return ;
	(*llist)->previos->next = *llist;
	*llist = (*llist)->next;
	(*llist)->previos->next = NULL;
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack)->next)
		return ;
	first = (*stack)->next;
	last = first;
	while (last->next)
		last = last->next;
	last->next = *stack;
	last->next->next = NULL;
	*stack = first;
}

char	*rotate_a(t_list **stack)
{
	rotate(stack);
	return (ft_strdup(RA));
}

char	*rotate_b(t_list **stack)
{
	rotate(stack);
	return (ft_strdup(RB));
}

char	*rotate_all(t_llist **llist)
{
	rotate_ll(llist);
	return (ft_strdup(RA));
}

char	*rotate_bll(t_llist **llist)
{
	rotate_ll(llist);
	return (ft_strdup(RB));
}
