/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:53:40 by polenyc           #+#    #+#             */
/*   Updated: 2024/01/22 15:45:36 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_max(t_list *stack)
{
	t_list	*tmp;
	int		max;

	if (!stack || !stack->content)
		return 0;
	max = *(int *)(stack->content);
	tmp = stack->next;
	while (tmp)
	{
		if (*(int *)(tmp->content) > max)
			max = *(int *)(tmp->content);
		tmp = tmp->next;
	}
	return (max);
}

char	*put_max(t_list **stack, int max, int size)
{
	if (*(int *)((*stack)->content) == max)
		return (rotate_a(stack));
	if (*(int *)((*stack)->next->content) == max && size > 2)
		return (rev_rotate_a(stack));
	return (ft_strdup(""));
}

char	*element_sort(t_list **stack)
{
	char	*operation;
	t_list	*tmp;
	int		size;

	size = ft_lstsize(*stack);
	if (size > 3 || size < 2)
		return (ft_strdup(""));
	operation = put_max(stack, find_max(*stack), size);
	if (size == 2)
		return (operation);
	if (*(int *)((*stack)->content) <= *(int *)((*stack)->next->content))
		return (operation);
	return (ft_strjoinfree(operation, swap_a(*stack), 2));
}
