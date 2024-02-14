/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:41:58 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/14 14:40:53 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sorts_alg.h"

void	swap(int *data, int i, int j)
{
	int	tmp;

	tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}

int	partition(int *data, int star, int end)
{
	int	x;
	int	i;
	int	j;

	x = data[end];
	i = star - 1;
	j = star;
	while (j < end)
	{
		if (data[j] <= x)
		{
			++i;
			swap(data, i, j);
		}
		++j;
	}
	++i;
	swap(data, i, end);
	return (i);
}

void	quick_sort(int *data, int f, int r)
{
	int	q;

	if (f < r)
	{
		q = partition(data, f, r);
		quick_sort(data, f, q - 1);
		quick_sort(data, q + 1, r);
	}
}

int	*quick_sort_insert(int *data, int f, int r)
{
	int	q;

	if (r - f < MAX_INS)
		return (insert_sort(data, f, r));
	q = rand_part(data, f, r);
	quick_sort(data, f, q - 1);
	quick_sort(data, q + 1, r);
	return (data);
}

void	quick_sort_rand(int *data, int f, int r)
{
	int	q;

	if (f < r)
	{
		q = rand_part(data, f, r);
		quick_sort(data, f, q - 1);
		quick_sort(data, q + 1, r);
	}
}
