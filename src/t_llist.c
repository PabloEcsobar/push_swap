/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_llist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:24:59 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/13 20:28:44 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_llist	*badmkllst(t_llist **llst, char **mat, int argc)
{
	if (argc == 2)
		freematrix(mat);
	return (llist_clear(llst, &del_node));
}

t_llist	*make_list(int argc, char **argv)
{
	t_llist	*llst;
	char	**tmp;
	int		i;

	llst = NULL;
	if (argc == 2)
		tmp = ft_split(argv[1], SPACE_S);
	else
		tmp = argv + 1;
	i = 0;
	while (tmp[i])
	{
		if (!checkstr(tmp[i]))
			return (badmkllst(&llst, tmp, argc));
		if (!add_back(&llst, newnode(make_data(ft_atoi(tmp[i])))))
			return (badmkllst(&llst, tmp, argc));
		++i;
	}
	if (argc == 2)
		freematrix(tmp);
	return (llst);
}