/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:54:22 by polenyc           #+#    #+#             */
/*   Updated: 2024/01/24 14:51:00 by blackrider       ###   ########.fr       */
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

// int test(int size)
// {
// 	t_list	*list;
// 	t_list	*tmp;
// 	// int		size;
// 	int		i;
// 	int		data;
// 	char	*oper;
// 	int		count;

// 	// printf("Enter a size of stack: \n");
// 	// scanf("%d", &size);
// 	list = NULL;
// 	for (int i= 0; i < size; ++i)
// 	{
// 		// printf("Enter an element of stack:\n");
// 		// scanf("%d", &data);
// 		data = rand() % 100;
// 		if (is_num(list, data))
// 		{
// 			--i;
// 			continue ;
// 		}
// 		ft_lstadd_back(&list, ft_lstnew(make_data(data)));
// 	}
// 	tmp = list;
// 	i = 0;
// 	while (tmp)
// 	{
// 		printf("list[%d]: %d\n", i, *(int *)(tmp->content));
// 		++i;
// 		tmp = tmp->next;
// 	}
// 	oper = push_swap(&list);
// 	tmp = list;
// 	i = 0;
// 	count = count_oper(oper);
// 	printf("operatnion for sort:\n%scount: %d\n", oper, count);
// 	free(oper);
// 	while (tmp)
// 	{
// 		printf("list[%d]: %d\n", i, *(int *)(tmp->content));
// 		++i;
// 		tmp = tmp->next;
// 	}
// 	ft_lstclear(&list, del_node);
// 	printf("-------------------/\\-----------------------------\n");
// 	return (count);
// }

int	test(int size)
{
	t_list	*list;
	t_list	*tmp;
	int		data;
	int		i;
	char	*oper;
	int		count;

	list = NULL;
	for (int i= 0; i < size; ++i)
	{
		data = rand() % 1000;
		if (is_num(list, data))
		{
			--i;
			continue ;
		}
		ft_lstadd_back(&list, ft_lstnew(make_data(data)));
	}
	oper = push_swap(&list);
	count = count_oper(oper);
	// printf("operatnion for sort:\n%scount: %d\n", oper, count);
	tmp = list;
	i = 0;
	// while (tmp)
	// {
	// 	printf("list[%d]: %d\n", i, *(int *)(tmp->content));
	// 	tmp = tmp->next;
	// 	++i;
	// }
	// printf("-------------------/\\-----------------------------\n");
	data = *(int *)(list->content);
	tmp = list->next;
	while (tmp)
	{
		if (data > *(int *)(tmp->content))
		{
			printf("ERROR!!! BAD SORT ALGORITHM!!!\n");
			return (-1);
		}
		data = *(int *)(tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&list, del_node);
	return (count);
}

int	main()
{
	int	count;
	int	size;
	int	oper;
	int	max;
	int	tmp;

	printf("Enter a count of tests: \n");
	scanf("%d", &count);
	printf("Enter a size of stack: \n");
	scanf("%d", &size);
	srand(time(NULL));
	oper = test(size);
	if (oper < 0)
		return (0);
	max = oper;
	for (int i = 0; i < count - 1; ++i)
	{
		tmp = test(size);
		if (tmp < 0)
			return (0);
		if (tmp > max)
			max = tmp;
		oper += tmp;
	}
	printf("Averege count of operation need for sort stack: %f\nmax number of operation: %d\n", (float)oper / (float)count, max);
	return (0);
}
