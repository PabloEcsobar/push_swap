/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:48:02 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/08 13:36:04 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

char	*rev_rotate_a(t_list **stack)
{
	rev_rotate(stack);
	return (ft_strdup(RRA));
}

char	*rev_rotate_b(t_list **stack)
{
	rev_rotate(stack);
	return (ft_strdup(RRB));
}

char	*rev_rotate_all(t_llist **llist)
{
	rev_rotate_ll(llist);
	return (ft_strdup(RRA));
}

char	*rev_rotate_bll(t_llist **llist)
{
	rev_rotate_ll(llist);
	return (ft_strdup(RRB));
}
