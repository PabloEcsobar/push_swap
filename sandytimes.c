/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandytimes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:18:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/26 16:21:46 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "push_swap.h"
#include "sorts_alg/sorts_alg.h"

static int		*make_arr(t_dllist *a, int size)
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

int			score(t_dllist *a, int num)
{
	t_dllist	*tmp;
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

char		*sndt_sort(t_dllist **a, t_dllist **b, int scatt)
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
		if (score(*a, arr[i + scatt]) < 1)
			while (*(int *)((*a)->data) > arr[i + scatt])
				oper = ft_strjoinfree(oper, rotate_all(a), 2);
		else
			while (*(int *)((*a)->data) > arr[i + scatt])
				oper = ft_strjoinfree(oper, rev_rotate_all(a), 2);
		oper = ft_strjoinfree(oper, push_bll(b, a), 2);
		if (*(int *)((*b)->data) < arr[i + scatt / 2])
			oper = ft_strjoinfree(oper, rotate_bll(b), 2);
		++i;
		if (i + scatt >= size)
			--scatt;
	}
	free(arr);
	return (oper);
}

char		*sndtimes(t_dllist **a, int scatter)
{
	char		*oper;
	int			*arr;
	int			i;
	t_dllist	*b;

	b = NULL;
	oper = sndt_sort(a, &b, scatter);
	*a = b;
	// while (b)
		// oper = ft_strjoinfree(oper, push_all(a, &b), 2);
	return (oper);
}