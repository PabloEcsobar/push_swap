/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:05:37 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/05 14:07:16 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../sorts_alg/sorts_alg.h"
#include <stdlib.h>
#include <stdio.h>

static int		*make_arr(t_list *a, int size)
{
	int	*arr;
	int	*tmp;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	tmp = arr;
	while (a)
	{
		*tmp = *(int *)(a->content);
		++tmp;
		a = a->next;
	}
	merge_insert(arr, 0, size - 1);
	return (arr);
}

char	*crt_b(t_list **b, t_list **a)
{
	char	*oper;

	oper = NULL;
	*b = NULL;
	while (*a)
		oper = ft_strjoinfree(oper, push_b(b, a), 2);
	return (oper);
}

char	*arr_sort(t_list **a)
{
	char	*oper;
	int		*arr;
	int		size;
	t_list	*b;

	size = ft_lstsize(*a);
	arr = make_arr(*a, size);
	if (!arr)
		return (NULL);
	oper = crt_b(&b, a);
	while (size)
	{
		--size;
		while (arr[size] != *(int *)(b->content))
			oper = ft_strjoinfree(oper, rotate_b(&b), 2);
		oper = ft_strjoinfree(oper, push_a(a, &b), 2);
	}
	free(arr);
	return (oper);
}

