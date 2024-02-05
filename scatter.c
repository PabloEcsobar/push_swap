/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:10:36 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/02 15:24:50 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pow/ft_pow.h"
#include <stdio.h>

double	scatter(int count)
{
	const double	b = 1;
	const double	k = 1.25;
    const double	m = 0.248;
	double			x;
	double			n;

	n = m * x / count;
    x = ft_pow((double)count, n);
    x = ft_pow(2, x);
	return (k * x + b);
}

int main(void)
{
	for (int i = 0; i < 1000; ++i)
		printf ("result[%d]:\t%f\n", i, scatter(i));
	return (0);
}