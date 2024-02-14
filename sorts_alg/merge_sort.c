/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:00:23 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/14 14:40:20 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sorts_alg.h"

int	rand_part(int *data, int star, int end)
{
	swap(data, rand() % end, end);
	return (partition(data, star, end));
}

int	*merge(int *data, int f, int r)
{
	int	q;

	if (f < r)
	{
		q = (f + r) / 2;
		if (!merge(data, f, q))
			return (NULL);
		if (!merge(data, q + 1, r))
			return (NULL);
		return (merge_sort(data, f, q, r));
	}
	return (data);
}
