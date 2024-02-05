/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:10:36 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/05 12:28:07 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pow/ft_pow.h"
#include <stdio.h>

double	scatter(int count)
{
	const int		min = 100;
	const int		max = 9197;
	const double	f = 2;
	const double	b = 1;
	const double	k_l = 0.11;
	const double	k_e = 1.25;
	const double	n = 0.2485;
	double			x;

	if (count < 1)
		return (0);
	if (count < min || count > max)
		return (b + k_l * count);
    x = ft_pow((double)count, n);
    x = ft_pow(f, x);
	return (k_e * x + b);
}
