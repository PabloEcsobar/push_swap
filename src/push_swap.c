/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:22:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/12 14:59:25 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "push_swap.h"
#include "../ft_pow/ft_pow.h"
#include "../ft_printf/headers/ft_printf_bonus.h"

t_list	*llst_tolst(t_llist *llst)
{
	t_list	*lst;

	while (llst)
	{
		ft_lstadd_back(&lst, ft_lstnew(make_data(*(int *)(llst->data))));
		llst = llst->next;
	}
	return (lst);
}

t_llist	*lst_tollst(t_list *lst)
{
	t_llist	*llst;

	llst = NULL;
	while (lst)
	{
		add_back(&llst, newnode(make_data(*(int *)(lst->content))));
		lst = lst->next;
	}
	return (llst);
}

char	*trivial_sort(t_llist **llst, t_llist **b)
{
	t_list		*lst;
	t_list		*b_tmp;
	char		*oper;

	lst = llst_tolst(*llst);
	b_tmp = NULL;
	oper = sort_b(&lst, &b_tmp, 3);
	llist_clear(llst, &del_node);
	*llst = lst_tollst(lst);
	ft_lstclear(&b_tmp, &del_node);
	llist_clear(b, &del_node);
	ft_lstclear(&lst, &del_node);
	return (oper);
}

char	*push_swap(t_llist **a, t_llist **b)
{
	char	*oper;

	if (!a || !(*a))
		return (NULL);
	if (llist_size(*a) < 10)
		return (trivial_sort(a, b));
	oper = sndtimes(a, b, round_num(scatter(llist_size(*a))));
	return (oper);
}
