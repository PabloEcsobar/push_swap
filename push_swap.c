/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:22:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/24 14:56:29 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "push_swap.h"

char	*push_swap(t_list **a)
{
	t_list	*b;
	char	*oper;

	if (!a || !(*a))
		return (NULL);
	if (ft_lstsize(*a) < 4)
		return (element_sort(a));
	b = NULL;
	oper = sort_b(a, &b, 3);
	ft_lstclear(&b, &del_node);
	return (oper);
}
