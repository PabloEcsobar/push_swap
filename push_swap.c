/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:22:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/22 15:46:48 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "push_swap.h"

char	*add_min(t_list **stack, t_list **b, int b_min, int b_max)
{
	char	*oper;

	if (*(int *)(*b)->content == b_min || *(int *)(*b)->content == b_max)
		return (push_b(b, stack));
	oper = NULL;
	while (b || *(int *)(*b)->content != b_min || *(int *)(*b)->content != b_max)
		oper = ft_strjoinfree(oper, rotate_b(b), 2);
	return (ft_strjoinfree(oper, push_b(stack, b), 2));
	
}

char	*add_b(t_list **stack, t_list **b, int b_max, int b_min)
{
	char	*oper;
	
	if (*(int *)(*stack)->content < b_min)
		
}

char	*sort_b(t_list **stack, t_list **b, int min_size)
{
	int		size_a;
	char	*oper;
	int		b_max;
	int		b_min;
	
	oper = NULL;
	size_a = ft_lstsize(*stack);
	b_min = ft_lstsize(*b) - 1;
	while (++b_min < min_size)
		oper = ft_strjoinfree(oper, push_b(b, stack), 2);
	oper = ft_strjoinfree(oper, element_sort(b), 2);
	b_max = *(int *)(*b)->content;
	b_min = *(int *)(*b)->next->content;
	while (size_a > min_size)
	{
		
		--size_a;
	}
}

char	*push_swap(t_list **stack)
{
	t_list	*b;
	
	if (!stack || !(*stack))
		return (NULL);
	if (ft_lstsize(*stack) < 4)
		return (element_sort(stack));
	b = 
}

