/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapapp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:07:40 by polenyc           #+#    #+#             */
/*   Updated: 2024/02/12 14:58:28 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../ft_printf/headers/ft_printf_bonus.h"
#include <stdlib.h>
#include <stdio.h>

int		checksuf(char *num)
{
	if (!(*num))
		return (1);
	if (*num == SPACE_S && ft_isdigit(*(num + 1)))
		return (1);
	if (*num == SPACE_S && issign(*(num + 1)) && ft_isdigit(*(num + 2)))
		return (1);
	return (0);
}

int		checkstr(char *str)
{
	if (!ft_isdigit(*str) && !issign(*str))
		return (0);
	++str;
	while (*str)
	{
		while (ft_isdigit(*str))
			++str;
		if (!checksuf(str))
			return (0);
		while (!ft_isdigit(*str) && *str != '\0')
		{
			++str;
			if (!(*str))
				return (0);
		}
	}
	return (1);
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
			return (llist_clear(&llst, &del_node));
		llst = add_back(&llst, newnode(make_data(ft_atoi(tmp[i]))));
		++i;
	}
	if (argc == 2)
		freematrix(tmp);
	return (llst);
}

int		checksort(t_llist *llst)
{
	int	data;

	data = *(int *)(llst->data);
	llst = llst->next;
	while (llst)
	{
		if (data >= *(int *)(llst->data))
			return (0);
		data = *(int *)(llst->data);
		llst = llst->next;
	}
	return (1);
}

int	pushswapapp(t_llist **a, t_llist **b, int argc, char **argv)
{
	char	*oper;

	if (argc < 2)
		return (dataerror("ERROR!!!"));
	*a = make_list(argc, argv);
	if (!*a)
		return (dataerror("ERROR!!!"));
	oper = push_swap(a, b);
	if (!oper || !checksort(*a))
	{
		llist_clear(a, &del_node);
		return (dataerror("ERROR!!!"));
	}
	ft_printf("%s", oper);
	llist_clear(a, &del_node);
	free(oper);
	return (1);
}

// int		main(int argc, char **argv)
// {
// 	t_llist	*llst;
// 	t_llist	*tmp;
// 	char	*oper;
// 	int		i;
// 	char	buffer[1024];
// 	int		size;

// 	i = 0;
// 	// argv = ft_split(*(argv + 1), SPACE_S);
// 	while (argv[i])
// 	{
// 		printf("argv[%d]: %s\n", i, argv[i]);
// 		++i;
// 	}
// 	llst = make_list(argc, argv);
// 	if (!llst)
// 	{
// 		printf("ERROR!!!\n");
// 		llist_clear(&llst, &del_node);
// 		return (-1);
// 	}
// 	tmp = llst;
// 	while (llst)
// 	{
// 		printf("result: %d\n", *(int *)(llst->data));
// 		llst = llst->next;
// 	}
// 	llst = tmp;
// 	oper = push_swap(&llst);
// 	printf("out sort\n");
// 	// if (!oper || !checksort(llst))
// 	// {
// 	// 	printf("ERROR!!!\n");
// 	// 	llist_clear(&llst, &del_node);
// 	// 	return (-1);
// 	// }
// 	while (llst)
// 	{
// 		printf("result: %d\n", *(int *)(llst->data));
// 		llst = llst->next;
// 	}
// 	return (0);
// }

// int		main(int argc, char **argv)
// {
// 	t_llist	*llst;
// 	int		i;
// 	// char	**argv;
// 	char	buffer[1024];
// 	int		size = 2;
// 	t_llist	*tmp;
// 	char	*oper;

// 	// printf("Enter count of number:\t");
// 	// scanf("%d", &size);
// 	// argv = malloc((size + 1) * sizeof(char *));
// 	// i = 0;
// 	// while (i < size)
// 	// {		
// 	// 	// tmp = getchar();
// 	// 	// while (tmp != '\n' && tmp != EOF)
// 	// 	// 	tmp = getchar();
// 	// 	printf("Enter a number:\n");
// 	// 	scanf("%s", buffer);
// 	// 	argv[i] = malloc((ft_strlen(buffer) + 1) * sizeof(char));
// 	// 	ft_strcpy(argv[i], buffer);
// 	// 	// if (i == 1)
// 	// 		// argv[i] = ft_strjoinfree(" ", argv[i], 1);
// 	// 	++i;
// 	// }
// 	// argv[size] = NULL;
// 	size = argc;	
// 	// i = 0;
// 	// while (i < size)
// 	// {
// 	// 	printf("argv[%d]: %s\n", i, argv[i]);
// 	// 	++i;
// 	// }
// 	llst = make_list(size + 1, argv);
// 	if (!llst)
// 	{
// 		printf("ERROR!!!\n");
// 		llist_clear(&llst, &del_node);
// 		return (-1);
// 	}
// 	// tmp = llst;
// 	// while (llst)
// 	// {
// 	// 	printf("result: %d\n", *(int *)(llst->data));
// 	// 	llst = llst->next;
// 	// }
// 	// llst = tmp;
// 	oper = push_swap(&llst);
// 	// tmp = llst;
// 	// while (llst)
// 	// {
// 	// 	printf("result sorting: %d\n", *(int *)(llst->data));
// 	// 	llst = llst->next;
// 	// }
// 	// llst = tmp;
// 	if (!oper || !checksort(llst))
// 	{
// 		printf("ERROR!!!\n");
// 		llist_clear(&llst, &del_node);
// 		return (-1);
// 	}
// 	while (llst)
// 	{
// 		printf("result: %d\n", *(int *)(llst->data));
// 		llst = llst->next;
// 	}
// 	return (0);
// }
