/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_insert_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:06:51 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/14 14:38:07 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sorts_alg.h"

int	*merge_insert(int *data, int f, int r)
{
	int	q;

	if (r - f < MAX_INS)
		return (insert_sort(data, f, r));
	q = (f + r) / 2;
	if (!merge_insert(data, f, q))
		return (NULL);
	if (!merge_insert(data, q + 1, r))
		return (NULL);
	return (merge_sort(data, f, q, r));
}
