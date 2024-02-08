/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:07:40 by polenyc           #+#    #+#             */
/*   Updated: 2024/02/08 21:39:18 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int		issign(char ch)
{
	if (ch != '+' && ch != '-')
		return (0);
	return (1);
}

int		checksuf(char *num)
{
	if (!(*num))
		return (1);
	if (*num == SPACE && ft_isdigit(*(num + 1)))
		return (1);
	if (*num == SPACE && issign(*(num + 1)) && ft_isdigit(*(num + 2)))
		return (1);
	return (0);
}

int		checkstr(char *str)
{
	int		var;

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

t_llist	*make_list(char **argv)
{
	t_llist	*llst;

	llst = NULL;
	++argv;
	while (*argv)
	{
		if (!checkstr(*argv))
			return (llist_clear(&llst, &del_node));
		llst = add_back(&llst, newnode(make_data(ft_atoi(*argv))));
		++argv;
	}
	return (llst);
}

// int		main(void)
// {
// 	t_llist	*llst;
// 	int		i;
// 	char	**argv;
// 	char	buffer[1024];
// 	int		size = 2;
// 	char	tmp;

// 	printf("Enter count of number:\t");
// 	scanf("%d", &size);
// 	argv = malloc((size + 1) * sizeof(char *));
// 	i = 0;
// 	while (i < size)
// 	{		
// 		// tmp = getchar();
// 		// while (tmp != '\n' && tmp != EOF)
// 		// 	tmp = getchar();
// 		printf("Enter a number:\n");
// 		scanf("%s", buffer);
// 		argv[i] = malloc((ft_strlen(buffer) + 1) * sizeof(char));
// 		ft_strcpy(argv[i], buffer);
// 		if (i == 1)
// 			argv[i] = ft_strjoinfree(" ", argv[i], 1);
// 		++i;
// 	}
// 	argv[size] = NULL;
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("argv[%d]: %s\n", i, argv[i]);
// 		++i;
// 	}
// 	llst = make_list(argv);
// 	if (!llst)
// 		printf("Error data!!!\n");
// 	while (llst)
// 	{
// 		printf("result: %d\n", *(int *)(llst->data));
// 		llst = llst->next;
// 	}
// 	return (0);
// }

int		main(int argc, char **argv)
{
	t_llist	*llst;
	int		i;
	char	buffer[1024];
	int		size;

	i = 0;
	// argv = ft_split(*(argv + 1), SPACE);
	while (i < size)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
		++i;
	}
	llst = make_list(argv);
	if (!llst)
		printf("Error data!!!\n");
	while (llst)
	{
		printf("result: %d\n", *(int *)(llst->data));
		llst = llst->next;
	}
	return (0);
}