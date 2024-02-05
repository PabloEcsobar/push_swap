/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandytimes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:18:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/02 14:51:47 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "push_swap.h"
#include "sorts_alg/sorts_alg.h"

static int		*make_arr(t_llist *a, int size)
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

int			score_a(t_llist *a, int num)
{
	t_llist	*tmp;
	int			counter;
	int			size;

	counter = 0;
	tmp = a;
	size = llist_size(a) + 1;
	size /= 2; 
	while (counter < size && *(int *)(tmp->data) > num)
	{
		tmp = tmp->next;
		++counter;
	}
	tmp = a->previos;
	--counter;
	while (counter > 0 && *(int *)(tmp->data) > num)
	{
		tmp = tmp->previos;
		--counter;
	}
	return (counter);
}

int			score_b(t_llist *a, int num)
{
	t_llist	*tmp;
	int			counter;
	int			size;

	counter = 0;
	tmp = a;
	size = llist_size(a) + 1;
	size /= 2; 
	while (counter < size && *(int *)(tmp->data) != num)
	{
		tmp = tmp->next;
		++counter;
	}
	tmp = a->previos;
	--counter;
	while (counter > 0 && *(int *)(tmp->data) != num)
	{
		tmp = tmp->previos;
		--counter;
	}
	return (counter);
}

char		*sndt_sort(t_llist **a, t_llist **b, int scatt)
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
		if (score_a(*a, arr[i + scatt]) < 1)
			while (*(int *)((*a)->data) > arr[i + scatt])
				oper = ft_strjoinfree(oper, rotate_all(a), 2);
		else
			while (*(int *)((*a)->data) > arr[i + scatt])
				oper = ft_strjoinfree(oper, rev_rotate_all(a), 2);
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

char		*sndtimes(t_llist **a, int scatter)
{
	char		*oper;
	int			*arr;
	int			size;
	int			i;
	t_llist	*b;

	b = NULL;
	oper = sndt_sort(a, &b, scatter);
	size = llist_size(b);
	arr = make_arr(b, size);
	i = 1;
	while (b && i <= size)
	{
		if (score_b(b, arr[size - i]) < 1)
			while (*(int *)(b->data) != arr[size - i])
				oper = ft_strjoinfree(oper, rotate_bll(&b), 2);
		else
			while (*(int *)(b->data) != arr[size - i])
				oper = ft_strjoinfree(oper, rev_rotate_bll(&b), 2);
		oper = ft_strjoinfree(oper, push_all(a, &b), 2);
		++i;
	}
	free(arr);
	return (oper);
}