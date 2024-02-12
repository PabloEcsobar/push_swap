/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:11:27 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/12 22:02:24 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/push_swap.h"
#include "get_next_line/get_next_line_bonus.h"
#include "ft_printf/headers/ft_printf_bonus.h"
#include <stdlib.h>
#include <stdio.h>

char	*applyoper(t_llist **a, t_llist **b, char *oper)
{
	if (!ft_strcmp(oper, RA))
		return (rotate_all(a));
	if (!ft_strcmp(oper, RB))
		return (rotate_bll(b));
	if (!ft_strcmp(oper, PA))
		return (push_all(a, b));
	if (!ft_strcmp(oper, PB))
		return (push_bll(b, a));
	if (!ft_strcmp(oper, RRA))
		return (rev_rotate_all(a));
	if (!ft_strcmp(oper, RRB))
		return (rev_rotate_bll(b));
	if (!ft_strcmp(oper, SA))
		return (swap_all(*a));
	if (!ft_strcmp(oper, SB))
		return (swap_bll(*b));
	return (NULL);
}

int     main(int argc, char **argv)
{
    char	*oper;
	char	*tmp;
	t_llist *a;
	t_llist *b;
	int		i;

	a = make_list(argc, argv);
	b = NULL;
	if (!a)
		return (-1);
	oper = get_next_line(0);
	i = 0;
	while (oper)
	{
		applyoper(&a, &b, oper);
		free(oper);
		oper = get_next_line(0);
		++i;
	}
	if (!checksort(a) || b)
	{
		llist_clear(&a, &del_node);
		llist_clear(&b, &del_node);
		return (dataerror("KO"));
	}
	ft_printf("count of operation: %d\n", i);
	ft_printf("OK\n");
	llist_clear(&a, &del_node);
    return (0);
}
