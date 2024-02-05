/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:54:22 by polenyc           #+#    #+#             */
/*   Updated: 2024/02/02 14:52:13 by blackrider       ###   ########.fr       */
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

int	is_numll(t_llist *list, int x)
{
	while (list)
	{
		if (*(int *)(list->data) == x)
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

t_list	*crt_randlist(int size)
{
	int		data;
	t_list	*list;

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
	return (list);
}

t_llist	*crt_randllist(int size)
{
	int			data;
	t_llist	*list;

	list = NULL;
	for (int i= 0; i < size; ++i)
	{
		data = rand() % 1000;
		if (is_numll(list, data))
		{
			--i;
			continue ;
		}
		add_back(&list, newnode(make_data(data)));
	}
	return (list);
}

// int	test(int size, int scatter)
// {
// 	t_llist	*list;
// 	t_llist	*tmp;
// 	int			data;
// 	int			i;
// 	char		*oper;
// 	int			count;

// 	list = crt_randllist(size);
// 	tmp = list;
// 	i = 0;
// 	while (tmp)
// 	{
// 		printf("list[%d]: %d\n", i, *(int *)(tmp->data));
// 		tmp = tmp->next;
// 		++i;
// 	}
// 	oper = sndtimes(&list, scatter);
// 	count = count_oper(oper);
// 	// printf("operatnion for sort:\n%scount: %d\n", oper, count);
// 	// printf("operation count: %d\n", count);
// 	tmp = list;
// 	i = 0;
// 	printf("\n");
// 	while (tmp)
// 	{
// 		printf("list[%d]: %d\n", i, *(int *)(tmp->data));
// 		tmp = tmp->next;
// 		++i;
// 	}
// 	printf("-------------------/\\-----------------------------\n");
// 	data = *(int *)(list->data);
// 	tmp = list->next;
// 	while (tmp)
// 	{
// 		if (data > *(int *)(tmp->data))
// 		{
// 			printf("ERROR!!! BAD SORT ALGORITHM!!!\n");
// 			return (-1);
// 		}
// 		data = *(int *)(tmp->data);
// 		tmp = tmp->next;
// 	}
// 	llist_clear(&list, del_node);
// 	return (count);
// }


int	test(int size, int scatter)
{
	t_llist	*list;
	t_llist	*tmp;
	int			data;
	int			i;
	char		*oper;
	int			count;

	list = crt_randllist(size);
	oper = sndtimes(&list, scatter);
	count = count_oper(oper);
	data = *(int *)(list->data);
	tmp = list->next;
	while (tmp)
	{
		if (data > *(int *)(tmp->data))
		{
			printf("ERROR!!! BAD SORT ALGORITHM!!!\n");
			return (-1);
		}
		data = *(int *)(tmp->data);
		tmp = tmp->next;
	}
	llist_clear(&list, del_node);
	return (count);
}

int	test_for_num(int count, int size, int scatter)
{
	int	oper;
	int	max;
	int	tmp;

	oper = test(size, scatter);
	if (oper < 0)
		return (0);
	max = oper;
	for (int i = 0; i < count - 1; ++i)
	{
		tmp = test(size, scatter);
		if (tmp < 0)
			return (0);
		if (tmp > max)
			max = tmp;
		oper += tmp;
	}
	printf("Averege count of operation need for sort stack with scatter %d: %f\tmax number of operation: %d\n", scatter, (float)oper / (float)count, max);
}

int	main()
{
	int	count;
	int	size;
	int sc_min;
	int	sc_max;

	srand(time(NULL));
	printf("Enter a count of tests: \n");
	scanf("%d", &count);
	printf("Enter a size of stack: \n");
	scanf("%d", &size);
	printf("Enter a min num of scatter:\n");
	scanf("%d", &sc_min);
	printf("Enter a max num of scatter:\n");
	scanf("%d", &sc_max);
	while (sc_min <= sc_max)
	{
		test_for_num(count, size, sc_min);
		++sc_min;
	}
	return (0);
}


// int	test(int size, int scatter)
// {
// 	t_llist	*list;
// 	t_llist	*tmp;
// 	int			data;
// 	int			i;
// 	char		*oper;
// 	int			count;

// 	list = crt_randllist(size);
// 	// tmp = list;
// 	// i = 0;
// 	// while (tmp)
// 	// {
// 	// 	printf("list[%d]: %d\n", i, *(int *)(tmp->data));
// 	// 	tmp = tmp->next;
// 	// 	++i;
// 	// }
// 	oper = sndtimes(&list, scatter);
// 	count = count_oper(oper);
// 	// printf("operatnion for sort:\n%scount: %d\n", oper, count);
// 	// printf("operation count: %d\n", count);
// 	// tmp = list;
// 	// i = 0;
// 	// printf("\n");
// 	// while (tmp)
// 	// {
// 	// 	printf("list[%d]: %d\n", i, *(int *)(tmp->data));
// 	// 	tmp = tmp->next;
// 	// 	++i;
// 	// }
// 	// printf("-------------------/\\-----------------------------\n");
// 	data = *(int *)(list->data);
// 	tmp = list->next;
// 	while (tmp)
// 	{
// 		if (data > *(int *)(tmp->data))
// 		{
// 			printf("ERROR!!! BAD SORT ALGORITHM!!!\n");
// 			return (-1);
// 		}
// 		data = *(int *)(tmp->data);
// 		tmp = tmp->next;
// 	}
// 	llist_clear(&list, del_node);
// 	return (count);
// }

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


// int	test(int size)
// {
// 	t_list	*list;
// 	t_list	*tmp;
// 	int		data;
// 	int		i;
// 	char	*oper;
// 	int		count;

// 	list = crt_randlist(size);
// 	oper = push_swap(&list);
// 	// oper = arr_sort(&list);
// 	count = count_oper(oper);
// 	// printf("operatnion for sort:\n%scount: %d\n", oper, count);
// 	tmp = list;
// 	i = 0;
// 	// while (tmp)
// 	// {
// 	// 	printf("list[%d]: %d\n", i, *(int *)(tmp->content));
// 	// 	tmp = tmp->next;
// 	// 	++i;
// 	// }
// 	// printf("-------------------/\\-----------------------------\n");
// 	data = *(int *)(list->content);
// 	tmp = list->next;
// 	while (tmp)
// 	{
// 		if (data > *(int *)(tmp->content))
// 		{
// 			printf("ERROR!!! BAD SORT ALGORITHM!!!\n");
// 			return (-1);
// 		}
// 		data = *(int *)(tmp->content);
// 		tmp = tmp->next;
// 	}
// 	ft_lstclear(&list, del_node);
// 	return (count);
// }
