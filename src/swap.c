/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:41:57 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/13 12:19:16 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

char	*swap_a(t_list *stack)
{
	swap_tl(stack);
	return (ft_strdup(SA));
}

char	*swap_b(t_list *stack)
{
	swap_tl(stack);
	return (ft_strdup(SB));
}

char	*swap_all(t_llist *llist)
{
	swap_ll(llist);
	return (ft_strdup(SA));
}

char	*swap_bll(t_llist *llist)
{
	swap_ll(llist);
	return (ft_strdup(SB));
}

char	*sswap_ll(t_llist *a, t_llist *b)
{
	swap_all(a);
	swap_bll(b);
	return (SS);
}
