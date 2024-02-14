/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_alg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:07:42 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/14 14:41:12 by blackrider       ###   ########.fr       */
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