/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:05:57 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/13 14:13:24 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"
#include "../ft_printf/headers/ft_printf_bonus.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_llist	*a;
	t_llist	*b;
	char	*oper;

	a = NULL;
	b = NULL;
	oper = pushswapapp(&a, &b, argc, argv);
	ft_printf("%s", oper);
	free(oper);
	return (0);
}
