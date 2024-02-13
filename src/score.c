/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:07:39 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/13 12:22:41 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	score_a(t_llist *a, int num)
{
	t_llist		*tmp;
	int			counter;
	int			size;

	counter = 0;
	tmp = a;
	size = llist_size(a) + 1;
	size /= 2;
	while (counter < size && *(int *)(tmp->data) > num)
	{
		tmp = tmp->next;
		++counter;
	}
	tmp = a->previos;
	if (counter && tmp->next && *(int *)(tmp->next->data) <= num)
		return (-2);
	--counter;
	while (counter > 0 && *(int *)(tmp->data) > num)
	{
		tmp = tmp->previos;
		--counter;
	}
	return (counter);
}

int	score_b(t_llist *a, int num)
{
	t_llist	*tmp;
	int		counter;
	int		size;

	counter = 0;
	tmp = a;
	size = llist_size(a) + 1;
	size /= 2;
	while (counter < size && *(int *)(tmp->data) != num)
	{
		tmp = tmp->next;
		++counter;
	}
	tmp = a->previos;
	if (counter && tmp->next && *(int *)(tmp->next->data) == num)
		return (-2);
	--counter;
	while (counter > 0 && *(int *)(tmp->data) != num)
	{
		tmp = tmp->previos;
		--counter;
	}
	return (counter);
}
