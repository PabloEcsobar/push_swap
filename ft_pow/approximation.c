/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   approximation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:39:21 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/09 15:04:26 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pow.h"
#include <stdlib.h>

double	approx_one(double num, int deg)
{
	double	res;
	double	tmp;

	tmp = 1.0 / deg;
	res = 1.0 + tmp;
	while (pow_int(res, deg) > num)
	{
		if (res > 1)
			res -= tmp / ((double)deg * num);
		if (res < 1)
		{
			tmp = pow_int((tmp / (num * (double)deg)), deg - 1);
			tmp /= pow_int(num * (double)deg, deg);
			res = 1.0 + tmp;
		}
	}
	while (pow_int(res * res, deg) < num)
		res *= res;
	return (res);
}

double	approx_pow(double num, int deg)
{
	double	res;

	deg = ft_abs(deg);
	num = ft_abs(num);
	res = num / (deg * deg);
	if (res <= 1)
		return (approx_one(num, deg));
	while (pow_int(res, deg) > num)
		res /= deg * deg;
	if (res <= 1)
		return (approx_one(num, deg));
	while (pow_int(res * res, deg) < num)
		res *= res;
	return (res);
}

int	*dennum(double num)
{
	int	*arr;
	int	tmp;

	arr = malloc(2 * sizeof(int));
	if (!arr)
		return (NULL);
	arr[1] = 1;
	while (arr[1] < MAXNUM && ft_abs(num - (int)num) > PRECISION)
	{
		num *= FTPOW_DEC;
		arr[1] *= FTPOW_DEC;
	}
	tmp = find_cmndv(num, arr[1]);
	arr[0] = round_num(num) / tmp;
	arr[1] = arr[1] / tmp;
	return (arr);
}

double	numlesone(double num, double deg)
{
	int		*arr;
	double	res;

	arr = dennum(num);
	if (!arr)
		return (-1.0);
	res = pow_float(arr[0], deg) / pow_float(arr[1], deg);
	free(arr);
	return (res);
}
