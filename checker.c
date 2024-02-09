/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:11:27 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/09 21:29:02 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/push_swap.h"
#include "get_next_line/get_next_line_bonus.h"
#include "ft_printf/headers/ft_printf_bonus.h"
#include <stdlib.h>
#include <unistd.h>

int     checker(int argc, char **argv)
{
    t_llist	*llst;
	char	*oper;
	char	*tmp;

	llst = make_list(argc, argv);
	if (!llst)
		return (-1);
	oper = NULL;
	tmp = get_next_line(0);
	pushswapapp(argc, argv);
	while (tmp)
	{
		ft_printf("result: %s", tmp);
		oper = ft_strjoinfree(oper, tmp, 2);
		tmp = get_next_line(0);
	}
	ft_printf("result: %s", tmp);
}

int     main(int argc, char **argv)
{
    checker(argc, argv);
    return (0);
}
