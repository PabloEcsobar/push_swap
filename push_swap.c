/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:22:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/22 12:56:18 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "push_swap.h"

char	*sort_b(t_list **stack, t_list **b, int min_size)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack);
	size_b = ft_lstsize(*b);
	while (size_a > min_size)
	{
		
		--size_a;
	}
}

char	*push_swap(t_list **stack)
{
	t_list	*b;
	
	if (!stack || !(*stack))
		return (NULL);
	if (ft_lstsize(*stack) < 4)
		return (element_sort(stack));
	b = 
}

