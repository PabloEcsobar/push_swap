/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:41:57 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/21 17:44:20 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	swap_tl(t_list *stack)
{
	t_list	tmp;

	if (!stack || !stack->next)
		return ;
	tmp.content = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp.content;
}

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
