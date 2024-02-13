/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:10:36 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/13 12:19:01 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_pow/ft_pow.h"
#include "push_swap.h"
#include <stdio.h>

double	scatter(int count)
{
	double			x;

	if (count < 1)
		return (0);
	if (count < PS_SCT_MIN || count > PS_SCT_MAX)
		return (PS_B + PS_K_L * count);
	x = ft_pow((double)count, PS_N);
	x = ft_pow(PS_BASIS_F, x);
	return (PS_K_E * x + PS_B);
}
