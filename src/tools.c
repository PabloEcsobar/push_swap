/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:09:38 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/08 17:38:13 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	*make_data(int x)
{
	int	*tmp;

	tmp = malloc(sizeof(int));
	if (!tmp)
		return (NULL);
	*tmp = x;
	return ((void *)tmp);
}

void	del_node(void *tmp)
{
	free(tmp);
}



