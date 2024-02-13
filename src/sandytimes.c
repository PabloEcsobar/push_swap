/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandytimes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:18:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/13 12:10:31 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "push_swap.h"
#include "../sorts_alg/sorts_alg.h"

static int	*make_arr(t_llist *a, int size)
{
	int	*arr;
	int	*tmp;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	tmp = arr;
	while (a)
	{
		*tmp = *(int *)(a->data);
		++tmp;
		a = a->next;
	}
	merge_insert(arr, 0, size - 1);
	return (arr);
}

char	*findcorel_a(t_llist **a, int *arr, int i)
{
	char	*oper;
	int		score;

	oper = NULL;
	score = score_a(*a, arr[i]);
	if (score < -1)
		return (swap_all(*a));
	if (score < 1)
	{
		while (*(int *)((*a)->data) > arr[i])
			oper = ft_strjoinfree(oper, rotate_all(a), 2);
		return (oper);
	}
	while (*(int *)((*a)->data) > arr[i])
		oper = ft_strjoinfree(oper, rev_rotate_all(a), 2);
	return (oper);
}

char	*sndt_sort(t_llist **a, t_llist **b, int scatt)
{
	char	*oper;
	int		*arr;
	int		size;
	int		i;

	oper = NULL;
	size = llist_size(*a);
	arr = make_arr(*a, size);
	i = 0;
	while (*a)
	{
		oper = ft_strjoinfree(oper, findcorel_a(a, arr, i + scatt), 2);
		oper = ft_strjoinfree(oper, push_bll(b, a), 2);
		if (*(int *)((*b)->data) < arr[i])
			oper = ft_strjoinfree(oper, rotate_bll(b), 2);
		++i;
		if (i + scatt >= size)
			--scatt;
	}
	free(arr);
	return (oper);
}

char	*findcorel_b(t_llist **b, int *arr, int i)
{
	char	*oper;
	int		score;

	oper = NULL;
	score = score_b(*b, arr[i]);
	if (score < -1)
		return (swap_bll(*b));
	if (score < 1)
	{
		while (*(int *)((*b)->data) != arr[i])
			oper = ft_strjoinfree(oper, rotate_bll(b), 2);
		return (oper);
	}
	while (*(int *)((*b)->data) != arr[i])
		oper = ft_strjoinfree(oper, rev_rotate_bll(b), 2);
	return (oper);
}

char	*sndtimes(t_llist **a, t_llist **b, int scatter)
{
	char		*oper;
	int			*arr;
	int			size;
	int			i;

	oper = sndt_sort(a, b, scatter);
	size = llist_size(*b);
	arr = make_arr(*b, size);
	i = 1;
	while (*b && i <= size)
	{
		oper = ft_strjoinfree(oper, findcorel_b(b, arr, size - i), 2);
		oper = ft_strjoinfree(oper, push_all(a, b), 2);
		++i;
	}
	free(arr);
	llist_clear(b, &del_node);
	return (oper);
}
