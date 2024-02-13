/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:00:56 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/09 15:04:24 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define MIN_DEV 1
#define DBL_MAX_ROOT_TEN 6690699980388652205836230197248.0
#define DBL_MAX_ROOT_HNDR 1209.336485
#define PRECISION 0.0000001
#define FTPOW_DEC 10
#define MAXNUM 1000000

double	ft_pow(double num, double deg);
double	approx_one(double num, int deg);
double	approx_pow(double num, int deg);
double	pow_int(double num, int deg);
double	pow_float(double num, double deg);
double	newtroot(double num, double deg, double approx);
////////////////////////TOOLS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
int		round_num(double num);
double	ft_abs(double num);
double	find_nearestr(double num, int root);
int		isprime(int x);
int		find_cmndv(int deg, int root);
double	root_av(double num, double deg, int root);
int		*dennum(double num);
double	numlesone(double num, double deg);