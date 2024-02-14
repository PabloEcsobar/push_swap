/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:15:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/14 14:01:51 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**crt_arrs(int *data, int f, int q, int r)
{
	int	**arr;
	int	i;
	int	size_f;
	int	size_r;

	arr = malloc(2 * sizeof(int *));
	if (!arr)
		return (NULL);
	size_f = q - f + 1;
	size_r = r - q;
	arr[0] = malloc((size_f) * sizeof(int));
	if (!arr[0])
		return (NULL);
	arr[1] = malloc((size_r) * sizeof(int));
	if (!arr[1])
		return (NULL);
	i = -1;
	while (++i < size_f)
		arr[0][i] = data[f + i];
	f += i;
	i = -1;
	while (++i < size_r)
		arr[1][i] = data[f + i];
	return (arr);
}

void	arr_free(int **arr, int size)
{
	while (size)
		free(arr[--size]);
	free(arr);
}

int	*merge_sort(int *data, int f, int q, int r)
{
	int	**arr;
	int	i;
	int	j;
	int	size_f;
	int	size_r;

	arr = crt_arrs(data, f, q, r);
	size_f = q - f + 1;
	size_r = r - q;
	i = 0;
	j = 0;
	while (i + j + f <= r)
	{
		if (j >= size_r || (i < size_f && arr[0][i] <= arr[1][j]))
		{
			data[i + j + f] = arr[0][i];
			++i;
			continue ;
		}
		data[i + j + f] = arr[1][j];
		++j;
	}
	arr_free(arr, 2);
	return (data);
}
