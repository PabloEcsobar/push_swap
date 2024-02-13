/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:09:38 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/13 13:39:02 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../ft_printf/headers/ft_printf_bonus.h"
#include <stdlib.h>
#include <limits.h>

void	*make_data(long x)
{
	int	*tmp;

	if (x > (long)INT_MAX || x < (long)INT_MIN)
		return (NULL);
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

char	*dataerror(char *msg)
{
	ft_printf("%s\n", msg);
	return (NULL);
}

int	issign(char ch)
{
	if (ch != '+' && ch != '-')
		return (0);
	return (1);
}

void	*freematrix(char **mat)
{
	char	**tmp;

	tmp = mat;
	while (*mat)
	{
		free(*mat);
		++mat;
	}
	free(tmp);
	return (NULL);
}
