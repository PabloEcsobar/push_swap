/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:00:29 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/24 15:02:07 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sorts_alg.h"

// int main()
// {
// 	int		*arr_m;
//     int     *arr_mi;
//     int     *arr_q;
//     int     *arr_qi;
//     double	cpu_time_mi;
//     double  cpu_time_m;
//     double  cpu_time_q;
//     double  cpu_time_qi;
// 	int		size;
// 	clock_t	start;
// 	clock_t	end;

// 	srand(time(NULL));
// 	printf("Enter a size of array: \n");
// 	scanf("%d",&size);
// 	arr_m = malloc(size * sizeof(int));
//     arr_mi = malloc(size * sizeof(int));
//     arr_q = malloc(size * sizeof(int));
//     arr_qi = malloc(size * sizeof(int));
// 	for (int i = 0; i < size; ++i)
//     {
// 		arr_m[i] = rand() % 1000000000;
//         arr_mi[i] = arr_m[i];
//         arr_q[i] = arr_m[i];
//         arr_qi[i] = arr_m[i];
//     }
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("arr_m[%d]: %d\tarr_mi[%d]: %d\tarr_q[%d]: %d\tarr_qi[%d], %d\n", i, arr_m[i], i, arr_mi[i], i, arr_q[i], i, arr_qi[i]);
//     start = clock();
// 	quick_sort_insert(arr_qi, 0, size - 1);
// 	end = clock();
// 	cpu_time_qi = (double)(end - start) / CLOCKS_PER_SEC;
//     start = clock();
// 	quick_sort(arr_q, 0, size - 1);
// 	end = clock();
// 	cpu_time_q = (double)(end - start) / CLOCKS_PER_SEC;
//     start = clock();
// 	merge(arr_m, 0, size - 1);
// 	end = clock();
// 	cpu_time_m = (double)(end - start) / CLOCKS_PER_SEC;
// 	start = clock();
// 	merge_insert(arr_mi, 0, size - 1);
// 	end = clock();
// 	cpu_time_mi = (double)(end - start) / CLOCKS_PER_SEC;
// 	printf("insert act. num: %d\tmerge sort: %f\tmerge_insert sort: %f\tdiv: %f\tquick s.: %f\tquick_insert s.: %f\n",
//      MAX_INS, cpu_time_m, cpu_time_mi, cpu_time_m - cpu_time_mi, cpu_time_q, cpu_time_qi);
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("arr_m[%d]: %d\tarr_mi[%d]: %d\tarr_q[%d]: %d\tarr_qi[%d], %d\n", i, arr_m[i], i, arr_mi[i], i, arr_q[i], i, arr_qi[i]);
// 	free(arr_mi);
//     free(arr_m);
//     free(arr_q);
//     free(arr_qi);
// 	return (0);
// }

// int main()
// {
// 	int		*arr;
// 	int		size;
// 	double	cpu_time_qs;
// 	clock_t	start;
// 	clock_t	end;

// 	srand(time(NULL));
// 	printf("Enter a size of array: \n");
// 	scanf("%d",&size);
// 	arr = malloc(size * sizeof(int));
// 	for (int i = 0; i < size; ++i)
// 		arr[i] = rand() % 1000;
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("arr[%d]: %d\n", i, arr[i]);
// 	start = clock();
// 	insert_sort(arr, 0, size - 1);
// 	end = clock();
// 	cpu_time_qs = (double)(end - start) / CLOCKS_PER_SEC;
// 	printf("insert sort time: %f\n", cpu_time_qs);
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("arr[%d]: %d\n", i, arr[i]);
// 	free(arr);
// 	return (0);
// }


// int main()
// {
// 	int		*arr;
// 	int		size;
// 	double	cpu_time_qs;
// 	clock_t	start;
// 	clock_t	end;

// 	srand(time(NULL));
// 	printf("Enter a size of array: \n");
// 	scanf("%d",&size);
// 	arr = malloc(size * sizeof(int));
// 	for (int i = 0; i < size; ++i)
// 		arr[i] = rand() % 100;
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("arr[%d]: %d\n", i, arr[i]);
// 	start = clock();
// 	merge(arr, 0, size - 1);
// 	end = clock();
// 	cpu_time_qs = (double)(end - start) / CLOCKS_PER_SEC;
// 	printf("merge sort time: %f\n", cpu_time_qs);
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("arr[%d]: %d\n", i, arr[i]);
// 	free(arr);
// 	return (0);
// }

// int main()
// {
// 	int		*data;
// 	int		*arr_r;
// 	int		size;
// 	int		j;
// 	double	cpu_time_rqs;
// 	double	cpu_time_qs;
// 	clock_t	start;
// 	clock_t	end;

// 	srand(time(NULL));
// 	printf("Enter a size of array: \n");
// 	scanf("%d",&size);
// 	data = malloc(size * sizeof(int));
// 	arr_r = malloc(size * sizeof(int));
// 	for (int i = 0; i < size; ++i)
// 	{
// 		data[i] = rand() % 10000;
// 		arr_r[i] = data[i];
// 	}
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("data[%d]: %d\n", i, data[i]);
// 	start = clock();
// 	quick_sort(data, 0, size - 1);
// 	end = clock();
// 	cpu_time_qs = (double)(end - start) / CLOCKS_PER_SEC;
// 	start = clock();
// 	quick_sort_rand(arr_r, 0, size - 1);
// 	end = clock();
// 	cpu_time_rqs = (double)(end - start) / CLOCKS_PER_SEC;
// 	printf("quick sort time: %f\trandom qs time: %f\n", cpu_time_qs, cpu_time_rqs);
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("data[%d]: %d\n", i, data[i]);
// 	return (0);
// }