/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacktools_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:35:07 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/08 13:38:04 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **dest, t_list **src)
{
	t_list *tmp;

	if (!(*src))
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
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

void	swap_tl(t_list *stack)
{
	t_list	tmp;

	if (!stack || !stack->next)
		return ;
	tmp.content = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp.content;
}