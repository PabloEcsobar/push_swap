/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:55:34 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/30 14:20:14 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define SA		"sa\n"
# define SB		"sb\n"
# define SS 	"ss\n"
# define PA 	"pa\n"
# define PB 	"pb\n"
# define RA 	"ra\n"
# define RB		"rb\n"
# define RR 	"rr\n"
# define RRA	"rra\n"
# define RRB	"rrb\n"
# define RRR	"rrr\n"

#include "ft_printf/libft/libft.h"

typedef struct			s_dllist
{
    void				*data;
    struct s_dllist		*next;
    struct s_dllist		*previos;
}						t_dllist;
//////////////////////////////LLIST\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_dllist	*newnode(void *data);
t_dllist	*add_back(t_dllist **llist, t_dllist *new);
t_dllist	*add_front(t_dllist **llist, t_dllist *new);
void		*llist_clear(t_dllist **llist, void (*del)(void *d));
int			llist_size(t_dllist *llist);
//////////////////////////////TOOLS LLIST\\\\\\\\\\\\\\\\\\\\\\\\\\\/
char		*push_all(t_dllist **dest, t_dllist **src);
char		*push_bll(t_dllist **dest, t_dllist **src);
char		*rotate_all(t_dllist **llist);
char		*rotate_bll(t_dllist **llist);
char		*rev_rotate_all(t_dllist **llist);
char		*rev_rotate_bll(t_dllist **llist);
char		*swap_all(t_dllist *llist);
char		*swap_bll(t_dllist *llist);
//////////////////////////////TOOLS\\\\\\\\\\\\\\\\\\\\\\\\\\\/
char	    *llst_tolst(t_dllist **llst);

void		push(t_list **dest, t_list **src);
char		*push_a(t_list **dest, t_list **src);
char		*push_b(t_list **dest, t_list **src);

void		swap_tl(t_list *stack);
char		*swap_a(t_list *stack);
char		*swap_b(t_list *stack);

void		rotate(t_list **stack);
char		*rotate_a(t_list **stack);
char		*rotate_b(t_list **stack);

void		rev_rotate(t_list **stack);
char		*rev_rotate_a(t_list **stack);
char		*rev_rotate_b(t_list **stack);

char		*element_sort(t_list **stack);
char		*elem_sort_b(t_list **b);
char		*push_swap(t_list **stack);

int			find_max(t_list *a);
int			find_min(t_list *a);
void		del_node(void *tmp);

char	    *sort_b(t_list **a, t_list **b, int min_size);
char	    *arr_sort(t_list **a);
char		*sndtimes(t_dllist **a, int scatter);

void	    *make_data(int x);