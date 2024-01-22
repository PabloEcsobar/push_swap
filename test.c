/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:54:22 by polenyc           #+#    #+#             */
/*   Updated: 2024/01/22 23:57:40 by blackrider       ###   ########.fr       */
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

int	is_num(t_list *list, int x)
{
	while (list)
	{
		if (*(int *)(list->content) == x)
			return (1);
		list = list->next;
	}
	return (0);
}

int	count_oper(char *oper)
{
	int count;

	count = 0;
	while (*oper)
	{
		if (*oper == '\n')
			++count;
		++oper;
	}
	return (count);
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
		data = rand() % 100;
		if (is_num(list, data))
		{
			--i;
			continue ;
		}
		ft_lstadd_back(&list, ft_lstnew(make_data(data)));
	}
	tmp = list;
	i = 0;
	while (tmp)
	{
		printf("list[%d]: %d\n", i, *(int *)(tmp->content));
		++i;
		tmp = tmp->next;
	}
	oper = push_swap(&list);
	tmp = list;
	i = 0;
	printf("operatnion for sort:\n%scount: %d\n", oper, count_oper(oper));
	while (tmp)
	{
		printf("list[%d]: %d\n", i, *(int *)(tmp->content));
		++i;
		tmp = tmp->next;
	}
	ft_lstclear(&list, del_node);
	return (0);
}
