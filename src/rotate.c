/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:44:48 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/08 13:35:49 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

char	*rotate_a(t_list **stack)
{
	rotate(stack);
	return (ft_strdup(RA));
}

char	*rotate_b(t_list **stack)
{
	rotate(stack);
	return (ft_strdup(RB));
}

char	*rotate_all(t_llist **llist)
{
	rotate_ll(llist);
	return (ft_strdup(RA));
}

char	*rotate_bll(t_llist **llist)
{
	rotate_ll(llist);
	return (ft_strdup(RB));
}
