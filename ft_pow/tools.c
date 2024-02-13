/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:33:30 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/04 00:55:22 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pow.h"

int	round_num(double num)
{
	if (num - (int)num < 0.5)
		return ((int)num);
	return ((int)num + 1);
}

double	ft_abs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	isprime(int x)
{
	int	num;

	if (x < 2)
		return (0);
	num = 2;
	while (num * num <= x)
	{
		if (x % num == 0)
			return (0);
		++num;
	}
	return (num);
}

int	find_cmndv(int deg, int root)
{
	int	max;
	int	i;

	if (!deg)
		return (1);
	if (!(root % deg))
		return (deg);
	max = 1;
	i = 2;
	while (i * i <= deg)
	{
		if (!(root % i) && !(deg % i))
			max = i;
		++i;
	}
	return (max);
}

double	root_av(double num, double deg, int root)
{
	while (ft_abs(deg - round_num(deg)) > 0.0000001)
	{
		deg *= 10;
		root *= 10;
	}
	deg = round_num(deg);
	root = round_num((double)root / deg);
	return (newtroot(num, (double)root, approx_pow(num, root)));
}
