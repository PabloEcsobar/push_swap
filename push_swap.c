/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:22:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/21 19:53:12 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "push_swap.h"

int		find_max(t_list *stack)
{
	t_list	*tmp;
	int		max;

	if (!stack || !stack->content)
		return 0;
	max = *(int *)(stack->content);
	tmp = stack->next;
	while (tmp)
	{
		if (*(int *)(tmp->content) > max)
			max = *(int *)(tmp->content);
		tmp = tmp->next;
	}
	return (max);
}

char	*put_max(t_list **stack, int max, int size)
{
	if (*(int *)((*stack)->content) == max)
		return (rotate_a(stack));
	if (*(int *)((*stack)->next->content) == max && size > 2)
		return (rev_rotate_a(stack));
	return (ft_strdup(""));
}

char	*element_sort(t_list **stack)
{
	char	*operation;
	t_list	*tmp;
	int		size;

	size = ft_lstsize(*stack);
	if (size > 3 || size < 2)
		return (ft_strdup(""));
	operation = put_max(stack, find_max(*stack), size);
	if (size == 2)
		return (operation);
	if (*(int *)((*stack)->content) <= *(int *)((*stack)->next->content))
		return (operation);
	return (strjoinfree(operation, swap_a(*stack), 2));
}

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
