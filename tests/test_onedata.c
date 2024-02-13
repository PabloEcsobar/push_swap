/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_onedata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:05:58 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/13 15:28:45 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "../src/push_swap.h"

void	*make_data_t(int x)
{
	int	*tmp;

	tmp = malloc(sizeof(int));
	if (!tmp)
		return (NULL);
	*tmp = x;
	return ((void *)tmp);
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

int	matrix(char *oper)
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
		add_back(&list, newnode(make_data_t(data)));
	}
	return (list);
}

t_llist	*crt_arrllist(int size)
{
	int			data;
	t_llist	*list;

	list = NULL;
    data = rand() % 1000;
	for (int i= 0; i < size; ++i)
		add_back(&list, newnode(make_data_t(i + data)));
	return (list);
}

t_llist	*llistcpy(t_llist *list)
{
    t_llist    *res;

	res = NULL;
    while (list)
    {
        add_back(&res, newnode(make_data_t(*(int *)(list->data))));
        list = list->next;
    }
    return (res);
}

int		found_n(t_llist *a, t_llist *b)
{
	t_llist	*tmp;

	if (!b && !a)
		return (1);
	if (!b || !a)
		return (0);
	while (a)
	{
		tmp = b;
		while (tmp && *(int *)(a->data) != *(int *)(tmp->data))
			tmp = tmp->next;
		if (!tmp)
			return (0);
		a = a->next;
	}
	return (1);
}

int			llstcmp(t_llist *a, t_llist *b)
{
	t_llist	*tmp;
	
	if (!b && !a)
		return (1);
	if (!b || !a)
		return (0);
	while (a)
	{
		tmp = b;
		while (tmp && *(int *)(a->data) != *(int *)(tmp->data))
			tmp = tmp->next;
		if (!tmp)
			return (0);
		a = a->next;
	}
	return (1);
}

int	bad_func(t_llist **a, t_llist **b, char *msg, void (*del)(void *))
{
	printf("%s\n", msg);
	llist_clear(a, del);
	llist_clear(b, del);
	return (-1);
}

int	test(t_llist *list, int scatter, void (*del)(void *))
{
	t_llist		*tmp;
	t_llist		*b;
	int			data;
	char		*oper;
	int			count;

	tmp = llistcpy(list);
	b = NULL;
	// if (llist_size(list) < 10)
	// 	oper = llst_tolst(&list);
	// else
	// 	oper = sndtimes(&list, scatter);
	oper = push_swap(&list, &b);
	// printf("INSTRUCTION:\n%s", oper);
	if (!llstcmp(tmp, list))
		return (bad_func(&list, &tmp, "ERROR!!! BAD SORT ALGORITHM!!!", del));
	llist_clear(&tmp, del);
	count = matrix(oper);
	data = *(int *)(list->data);
	tmp = list->next;
	while (tmp)
	{
		if (data > *(int *)(tmp->data))
			return (bad_func(&list, &tmp, "ERROR!!! BAD SORT ALGORITHM!!!", del));
		data = *(int *)(tmp->data);
		tmp = tmp->next;
	}
	llist_clear(&list, del);
	return (count);
}

void	*bad_test(t_llist **list, float **arr, void (*del)(void *))
{
	float	**tmp;

	llist_clear(list, del);
	tmp = arr;
	while (tmp)
	{
		free(*tmp);
		++tmp;
	}
	free(arr);
	return (NULL);
}

float	**crtmatrix(int count, int size)
{
	int		i;
	float	**arr;

	arr = malloc((count + 1) * sizeof(float *));
	// if (!matrix)
	// 	return (NULL);
	i = 0;
	while (i < count)
	{
		arr[i] = calloc(size, sizeof(float));
		if (!arr[i])
			return (NULL);
		++i;
	}
	arr[count] = NULL;
	return (arr);
}

float	**test_for_scat(int count, int size, int sc_min, int sc_max)
{
	int			i;
	int			j;
	int			tmp;
	float		**matrix;
	t_llist	*original;

	matrix = crtmatrix(sc_max - sc_min + 1, 2);
	i = 0;
	while (i < count)
	{
		original = crt_randllist(size);
		j = 0;
		while (j <= sc_max - sc_min)
		{
			tmp = test(llistcpy(original), sc_min + j, &del_node);
			if (tmp < 0)
				return (bad_test(&original, matrix, &del_node));
			if (tmp > (int)matrix[j][0])
				matrix[j][0] = (float)tmp;
			matrix[j][1] += (float)tmp;
			++j;
		}
		llist_clear(&original, &del_node);
		++i;
	}
	return (matrix);
}

int		test_for_num(int count, int size, int sc_min, int sc_max)
{
	int		i;
	int		j;
	float	**matrix;

	matrix = test_for_scat(count, size, sc_min, sc_max);
	if (!matrix)
		return (-1);
	i = -1;
	while (++i <= sc_max - sc_min)
	{
		matrix[i][1] /= (float)count;
		printf("Averege count of operation need for sort stack with scatter %d: %f\tmax number of operation: %d\n", 
		sc_min + i, matrix[i][1], (int)matrix[i][0]);
	}
	free(matrix);
	return (1);
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
	
	test_for_num(count, size, sc_min, sc_max);
	return (0);
}