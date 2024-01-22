/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:40:22 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/22 23:47:44 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

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
