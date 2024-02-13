/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:53:40 by polenyc           #+#    #+#             */
/*   Updated: 2024/02/13 12:02:13 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *a)
{
	int		max;

	if (!a || !a->content)
		return (0);
	max = *(int *)(a->content);
	a = a->next;
	while (a)
	{
		if (*(int *)(a->content) > max)
			max = *(int *)(a->content);
		a = a->next;
	}
	return (max);
}

int	find_min(t_list *a)
{
	int		min;

	if (!a || !a->content)
		return (0);
	min = *(int *)(a->content);
	a = a->next;
	while (a)
	{
		if (*(int *)(a->content) < min)
			min = *(int *)(a->content);
		a = a->next;
	}
	return (min);
}

char	*put_max(t_list **a, int max, int size, int pos)
{
	if (!pos)
	{
		if (*(int *)((*a)->content) == max)
			return (rotate_a(a));
		if (*(int *)((*a)->next->content) == max && size > 2)
			return (rev_rotate_a(a));
		return (ft_strdup(""));
	}
	if (*(int *)((*a)->content) == max)
		return (ft_strdup(""));
	if (*(int *)((*a)->next->content) == max && size > 2)
		return (swap_a(*a));
	return (rev_rotate_a(a));
}

char	*element_sort(t_list **a)
{
	char	*operation;
	int		size;

	size = ft_lstsize(*a);
	if (size > 3 || size < 2)
		return (ft_strdup(""));
	operation = put_max(a, find_max(*a), size, 0);
	if (size == 2)
		return (operation);
	if (*(int *)((*a)->content) <= *(int *)((*a)->next->content))
		return (operation);
	return (ft_strjoinfree(operation, swap_a(*a), 2));
}

char	*elem_sort_b(t_list **b)
{
	if (!(*b)->next)
		return (ft_strdup(""));
	if (*(int *)((*b)->content) > *(int *)((*b)->next->content))
		return (ft_strdup(""));
	return (swap_b(*b));
}
