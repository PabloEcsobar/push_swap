/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_alg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:07:42 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/14 14:44:29 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define MAX_INS 53

int		*insert_sort(int *data, int f, int r);
int		*merge(int *data, int f, int r);
int		*merge_insert(int *data, int f, int r);
void	quick_sort(int *arr, int p, int r);
void	quick_sort_rand(int *arr, int p, int r);
int		*quick_sort_insert(int *data, int f, int r);

int		*merge_sort(int *data, int f, int q, int r);
int		rand_part(int *data, int star, int end);
void	swap(int *data, int i, int j);
int		partition(int *data, int star, int end);
