/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:22:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/30 14:35:50 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "push_swap.h"

char	*llst_tolst(t_dllist **llst)
{
	t_dllist	*orig;
	t_list		*lst;
	t_list		*b;
	char		*oper;

	lst = NULL;
	orig = *llst;
	while (orig)
	{
		ft_lstadd_back(&lst, ft_lstnew(make_data(*(int *)(orig->data))));
		orig = orig->next;
	}
	b = NULL;
	oper = sort_b(&lst, &b, 3);
	ft_lstclear(&b, &del_node);
	llist_clear(llst, &del_node);
	*llst = NULL;
	b = lst;
	while (b)
	{
		add_back(llst, newnode(make_data(*(int *)(b->content))));
		b = b->next;
	}
	ft_lstclear(&lst, &del_node);
	return (oper);
}

char	*push_swap(t_list **a)
{
	t_list	*b;
	char	*oper;

	if (!a || !(*a))
		return (NULL);
	if (ft_lstsize(*a) < 11)
		return (element_sort(a));
	b = NULL;
	oper = sort_b(a, &b, 3);
	ft_lstclear(&b, &del_node);
	return (oper);
}
