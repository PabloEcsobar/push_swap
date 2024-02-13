/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerbonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:32:10 by polenyc           #+#    #+#             */
/*   Updated: 2024/02/13 13:37:45 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"
#include "../get_next_line/get_next_line_bonus.h"
#include "../ft_printf/headers/ft_printf_bonus.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*oper;
	t_llist	*a;
	t_llist	*b;

	a = NULL;
	b = NULL;
	pushswapapp(&a, &b, argc, argv);
	oper = get_next_line(0);
	ft_printf("result: %s\n", oper);
	return (0);
}