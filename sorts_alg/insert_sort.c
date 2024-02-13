/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:51:47 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/24 15:03:01 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*insert_sort(int *data, int f, int r)
{
	int	i;
	int	j;
	int	key;

	if (f < 0 || f > r)
		return (NULL);
	i = f + 1;
	while (i <= r)
	{
		key = data[i];
		j = i - 1;
		while (j >= f && data[j] > key)
		{
			data[j + 1] = data[j];
			--j;
		}
		data[j + 1] = key;
		++i;
	}
	return (data);
}
