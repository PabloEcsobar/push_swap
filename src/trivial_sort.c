/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivial_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:54:48 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/05 14:10:00 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "push_swap.h"

char	*add_min(t_list **a, t_list **b, int *b_max, int *b_min)
{
	char	*oper;

	if (!(*b) || !(*a))
		return (NULL);
	if (*(int *)(*b)->content == *b_max)
		return (*b_min = *(int *)((*a)->content), push_b(b, a));
	oper = NULL;
	while (*(int *)(*b)->content != *b_max)
		oper = ft_strjoinfree(oper, rotate_b(b), 2);
	*b_min = *(int *)((*a)->content);
	return (ft_strjoinfree(oper, push_b(b, a), 2));
}

char	*add_max(t_list **a, t_list **b, int *b_max)
{
	char	*oper;

	if (!(*b) || !(*a))
		return (NULL);
	if (*(int *)(*b)->content == *b_max)
		return (*b_max = *(int *)((*a)->content), push_b(b, a));
	oper = NULL;
	while (*(int *)(*b)->content != *b_max)
		oper = ft_strjoinfree(oper, rotate_b(b), 2);
	*b_max = *(int *)((*a)->content);
	return (ft_strjoinfree(oper, push_b(b, a), 2));
}

char	*add_b(t_list **a, t_list **b, int *b_max, int *b_min)
{
	char	*oper;
	int		prev;
	int		data;
	
	if (*(int *)(*a)->content < *b_min)
		return (add_min(a, b, b_max, b_min));
	if (*(int *)(*a)->content > *b_max)
		return (add_max(a, b, b_max));
	oper = NULL;
	prev = *(int *)(*b)->content;
	data = *(int *)(*a)->content;
	while (data > prev || data < *(int *)(*b)->next->content)
	{
		oper = ft_strjoinfree(oper, rotate_b(b), 2);
		prev = *(int *)(*b)->content;
	}
	oper = ft_strjoinfree(oper, rotate_b(b), 2);
	return (ft_strjoinfree(oper, push_b(b, a), 2));
}

char	*sort_a(t_list **a, t_list **b)
{
	char	*oper;
	int		max;
	int		min;
	int		av;

	oper = element_sort(a);
	max = *(int *)((*a)->next->next->content);
	av = *(int *)((*a)->next->content);
	min = *(int *)((*a)->content);

	while (*b && *(int *)((*b)->content) > max)
		oper = ft_strjoinfree(oper, push_a(a, b), 2);
	oper = ft_strjoinfree(oper, rev_rotate_a(a), 2);
	while (*b && *(int *)((*b)->content) > av)
		oper = ft_strjoinfree(oper, push_a(a, b), 2);
	oper = ft_strjoinfree(oper, rev_rotate_a(a), 2);
	while (*b && *(int *)((*b)->content) > min)
		oper = ft_strjoinfree(oper, push_a(a, b), 2);
	oper = ft_strjoinfree(oper, rev_rotate_a(a), 2);
	while (*b)
		oper = ft_strjoinfree(oper, push_a(a, b), 2);
	return (oper);
}

char	*sort_b(t_list **a, t_list **b, int min_size)
{
	int		size;
	char	*oper;
	int		*b_max;
	int		*b_min;
	
	if (ft_lstsize(*a) <= min_size)
		return (element_sort(a));
	oper = NULL;
	b_min = malloc(sizeof(int));
	b_max = malloc(sizeof(int));
	*b_min = ft_lstsize(*b);
	size = ft_lstsize(*a) + 1;
	while (--size > min_size && ++(*b_min) < min_size)
		oper = ft_strjoinfree(oper, push_b(b, a), 2);
	oper = ft_strjoinfree(oper, elem_sort_b(b), 2);
	*b_max = *(int *)(*b)->content;
	if ((*b)->next)
		*b_min = *(int *)(*b)->next->content;
	++size;
	while (--size > min_size)
		oper = ft_strjoinfree(oper, add_b(a, b, b_max, b_min), 2);
	while (*(int *)((*b)->content) != *b_max)
		oper = ft_strjoinfree(oper, rotate_b(b), 2);
	return (ft_strjoinfree(oper, sort_a(a, b), 2));
}
