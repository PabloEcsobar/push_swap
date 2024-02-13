/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:24:51 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/06 22:38:53 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pow.h"
#include <stdlib.h>
#include <stdio.h>

double	pow_int(double num, int deg)
{
	int		deg_abs;
	double	x;

	deg_abs = ft_abs(deg);
	x = num;
	while (deg_abs > 1)
	{
		num *= x;
		--deg_abs;
	}
	if (x < 0 && deg < 0 && num > 0)
		num *= -1;
	if (deg < 0)
		return (1 / num);
	return (num);
}

double	newtroot(double num, double deg, double approx)
{
	double	tmp;
	double	prec;
	double	err;

	prec = (num * deg) / 80000000000;
	tmp = pow_int(approx, deg);
	while (ft_abs(num - tmp) > prec)
	{
		err = num - tmp;
		approx = approx + err / (deg * tmp / approx);
		tmp = pow_int(approx, deg);
	}
	return (approx);
}

double	find_nearestr(double num, int root)
{
	const double	dec = 10.0;
	const double	duo = 2.0;
	double			res;
	int				tmp;

	tmp = isprime(root);
	if (root < 20 && tmp)
		return (newtroot(num, root, approx_pow(num, root)));
	if (tmp)
	{
		res = find_nearestr(num, root / dec);
		res = newtroot(res, dec / duo, approx_pow(res, dec / duo));
		return (newtroot(res, duo, approx_pow(res, duo)));
	}
	tmp = 2;
	while (tmp * tmp <= root)
	{
		if (root % tmp == 0)
			break ;
		++tmp;
	}
	res = find_nearestr(num, root / tmp);
	return (find_nearestr(res, tmp));
}

double	pow_float(double num, double deg)
{
	int		root;
	int		tmp;
	double	res;

	if (num < 0)
		return (0);
	if (num > 1 - PRECISION && num < 1 + PRECISION)
		return (1.0);
	deg = deg - (int)deg;
	root = 1;
	res = 1;
	while (ft_abs(deg - round_num(deg)) > PRECISION && root < MAXNUM)
	{
		deg = (deg - (int)deg) * 10;
		root *= 10;
		tmp = ft_abs(deg - round_num(deg));
		if (tmp && tmp < PRECISION)
			++deg;
		tmp = find_cmndv(deg, root);
		res *= find_nearestr(pow_int(num, deg / (double)tmp), root / tmp);
	}
	if (root > 1000000)
		return (res * root_av(num, deg, root));
	return (res);
}

double	ft_pow(double num, double deg)
{
	if (!deg && !num)
		return (0);
	if (!deg)
		return (num / ft_abs(num));
	if (!num)
		return (num);
	if (num > 1.0 - PRECISION && num < 1 + PRECISION)
		return (1.0);
	if (num < 1)
		return (numlesone(num, deg));
	if (deg - (int)deg < PRECISION)
		return (pow_int(num, (int)deg));
	if (deg < 1)
		return (pow_float(num, deg));
	return (pow_int(num, (int)deg) * pow_float(num, deg - (int)deg));
}
