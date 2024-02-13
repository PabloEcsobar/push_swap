/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerbonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:32:10 by polenyc           #+#    #+#             */
/*   Updated: 2024/02/13 14:38:32 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"
#include "../get_next_line/get_next_line_bonus.h"
#include "../ft_printf/headers/ft_printf_bonus.h"
#include <stdlib.h>
#include <stdio.h>

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

void	sort_forcheck(t_llist **a, t_llist **b)
{
	char	*oper;

	oper = get_next_line(0);
	while (oper && ft_strcmp(oper, "q\n"))
	{
		applyoper(a, b, oper);
		oper = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_llist	*a;
	t_llist	*b;

	b = NULL;
	a = make_list(argc, argv);
	sort_forcheck(&a, &b);
	if (!checksort(a) || b)
	{
		ft_printf("KO\n");
		llist_clear(&a, &del_node);
		llist_clear(&b, &del_node);
		return (-1);
	}
	ft_printf("OK\n");
	llist_clear(&a, &del_node);
	return (0);
}