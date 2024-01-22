/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:22:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/22 23:52:53 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "push_swap.h"

char	*add_min(t_list **stack, t_list **b, int *b_max, int *b_min)
{
	char	*oper;

	if (!(*b) || !(*stack))
		return (NULL);
	if (*(int *)(*b)->content == *b_max)
		return (*b_min = *(int *)((*stack)->content), push_b(b, stack));
	oper = NULL;
	while (*(int *)(*b)->content != *b_max)
		oper = ft_strjoinfree(oper, rotate_b(b), 2);
	*b_min = *(int *)((*stack)->content);
	return (ft_strjoinfree(oper, push_b(b, stack), 2));
}

char	*add_max(t_list **stack, t_list **b, int *b_max)
{
	char	*oper;

	if (!(*b) || !(*stack))
		return (NULL);
	if (*(int *)(*b)->content == *b_max)
		return (*b_max = *(int *)((*stack)->content), push_b(b, stack));
	oper = NULL;
	while (*(int *)(*b)->content != *b_max)
		oper = ft_strjoinfree(oper, rotate_b(b), 2);
	*b_max = *(int *)((*stack)->content);
	return (ft_strjoinfree(oper, push_b(b, stack), 2));
}

char	*add_b(t_list **stack, t_list **b, int *b_max, int *b_min)
{
	char	*oper;
	int		prev;
	int		data;
	
	if (*(int *)(*stack)->content < *b_min)
		return (add_min(stack, b, b_max, b_min));
	if (*(int *)(*stack)->content > *b_max)
		return (add_max(stack, b, b_max));
	oper = NULL;
	prev = *(int *)(*b)->content;
	data = *(int *)(*stack)->content;
	while (data > prev || data < *(int *)(*b)->next->content)
	{
		oper = ft_strjoinfree(oper, rotate_b(b), 2);
		prev = *(int *)(*b)->content;
	}
	oper = ft_strjoinfree(oper, rotate_b(b), 2);
	return (ft_strjoinfree(oper, push_b(b, stack), 2));
}

char	*sort_b(t_list **stack, t_list **b, int min_size)
{
	t_list	*tmp;
	int		size;
	char	*oper;
	int		*b_max;
	int		*b_min;
	
	oper = NULL;
	b_min = malloc(sizeof(int));
	b_max = malloc(sizeof(int));
	*b_min = ft_lstsize(*b);
	while (++(*b_min) < min_size)
		oper = ft_strjoinfree(oper, push_b(b, stack), 2);
	oper = ft_strjoinfree(oper, elem_sort_b(b), 2);
	*b_max = *(int *)(*b)->content;
	*b_min = *(int *)(*b)->next->content;
	size = ft_lstsize(*stack) + 1;
	while (--size)
		oper = ft_strjoinfree(oper, add_b(stack, b, b_max, b_min), 2);
	while (*(int *)((*b)->content) != *b_max)
		oper = ft_strjoinfree(oper, rotate_b(b), 2);
	size = ft_lstsize(*b) + 1;
	while (--size)
		oper = ft_strjoinfree(oper, push_a(stack, b), 2);
	return (oper);
}

char	*push_swap(t_list **stack)
{
	t_list	*b;
	char	*oper;

	if (!stack || !(*stack))
		return (NULL);
	if (ft_lstsize(*stack) < 4)
		return (element_sort(stack));
	b = NULL;
	oper = sort_b(stack, &b, 3);
	ft_lstclear(&b, &del_node);
	return (oper);
}
