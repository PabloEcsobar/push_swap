/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:11:27 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/14 14:03:05 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"
#include "../get_next_line/get_next_line_bonus.h"
#include "../ft_printf/headers/ft_printf_bonus.h"
#include <stdlib.h>
#include <stdio.h>

int	error_main(char *msg, int errcode)
{
	ft_printf("%s\n", msg);
	return (errcode);
}

char	*applyoper(t_llist **a, t_llist **b, char *oper)
{
	if (!ft_strcmp(oper, RA))
		return (rotate_all(a));
	if (!ft_strcmp(oper, RB))
		return (rotate_bll(b));
	if (!ft_strcmp(oper, RR))
		return (rrotate_ll(a, b));
	if (!ft_strcmp(oper, PA))
		return (push_all(a, b));
	if (!ft_strcmp(oper, PB))
		return (push_bll(b, a));
	if (!ft_strcmp(oper, RRA))
		return (rev_rotate_all(a));
	if (!ft_strcmp(oper, RRB))
		return (rev_rotate_bll(b));
	if (!ft_strcmp(oper, RRR))
		return (rrrevrotate_ll(a, b));
	if (!ft_strcmp(oper, SA))
		return (swap_all(*a));
	if (!ft_strcmp(oper, SB))
		return (swap_bll(*b));
	if (!ft_strcmp(oper, SS))
		return (sswap_ll(*a, *b));
	return (NULL);
}

int	main(int argc, char **argv)
{
	char	*oper;
	t_llist	*a;
	t_llist	*b;

	if (argc < 2)
		return (0);
	oper = get_next_line(0);
	a = make_list(argc, argv);
	b = NULL;
	if (!a)
		return (error_main("KO", -1));
	while (oper && ft_strcmp(oper, "q\n"))
	{
		applyoper(&a, &b, oper);
		free(oper);
		oper = get_next_line(0);
	}
	free(oper);
	if (!checksort(a) || b)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	llist_clear(&a, &del_node);
	llist_clear(&b, &del_node);
	return (0);
}
