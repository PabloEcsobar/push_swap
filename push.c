/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:40:22 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/29 14:46:18 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	push_ll(t_dllist **dest, t_dllist **src)
{
	t_dllist	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	if ((*src)->next)
		(*src)->next->previos = (*src)->previos;
	*src = (*src)->next;
	if (!(*dest))
	{
		tmp->next = NULL;
		tmp->previos = tmp;
		*dest = tmp;
		return ;
	}
	tmp->next = *dest;
	tmp->previos = (*dest)->previos;
	(*dest)->previos = tmp;
	*dest = tmp;
}

void	push(t_list **dest, t_list **src)
{
	t_list *tmp;

	if (!(*src))
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

char	*push_a(t_list **dest, t_list **src)
{
	push(dest, src);
	return (ft_strdup(PA));
}

char	*push_b(t_list **dest, t_list **src)
{
	push(dest, src);
	return (ft_strdup(PB));
}

char	*push_all(t_dllist **dest, t_dllist **src)
{
	push_ll(dest, src);
	return (ft_strdup(PA));
}

char	*push_bll(t_dllist **dest, t_dllist **src)
{
	push_ll(dest, src);
	return (ft_strdup(PB));
}
