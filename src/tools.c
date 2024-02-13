/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:09:38 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/13 12:21:33 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../ft_printf/headers/ft_printf_bonus.h"
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

int	dataerror(char *msg)
{
	ft_printf("%s\n", msg);
	return (-1);
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
