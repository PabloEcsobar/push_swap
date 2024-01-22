/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:54:22 by polenyc           #+#    #+#             */
/*   Updated: 2024/01/22 12:54:49 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "push_swap.h"

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

int	main()
{
	t_list	*list;
	t_list	*tmp;
	int		size;
	int		i;
	int		data;
	char	*oper;

	srand(time(NULL));
	printf("Enter a size of stack: \n");
	scanf("%d", &size);
	list = NULL;
	for (int i= 0; i < size; ++i)
	{
		// printf("Enter an element of stack:\n");
		// scanf("%d", &data);
		ft_lstadd_back(&list, ft_lstnew(make_data(rand() % 10)));
	}
	tmp = list;
	i = 0;
	while (tmp)
	{
		printf("list[%d]: %d\n", i, *(int *)(tmp->content));
		++i;
		tmp = tmp->next;
	}
	oper = element_sort(&list);
	tmp = list;
	i = 0;
	printf("operatnion for sort:\n%s", oper);
	while (tmp)
	{
		printf("list[%d]: %d\n", i, *(int *)(tmp->content));
		++i;
		tmp = tmp->next;
	}
	ft_lstclear(&list, del_node);
	return (0);
}
