/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:40:22 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/08 13:37:56 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

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

char	*push_all(t_llist **dest, t_llist **src)
{
	push_ll(dest, src);
	return (ft_strdup(PA));
}

char	*push_bll(t_llist **dest, t_llist **src)
{
	push_ll(dest, src);
	return (ft_strdup(PB));
}
