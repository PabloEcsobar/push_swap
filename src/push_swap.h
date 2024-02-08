/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:55:34 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/08 13:39:25 by blackrider       ###   ########.fr       */
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

#include "../ft_printf/libft/libft.h"

typedef struct			s_llist
{
    void				*data;
    struct s_llist		*next;
    struct s_llist		*previos;
}						t_llist;
//////////////////////////////LLIST\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_llist	    *newnode(void *data);
t_llist	    *add_back(t_llist **llist, t_llist *new);
t_llist	    *add_front(t_llist **llist, t_llist *new);
void		*llist_clear(t_llist **llist, void (*del)(void *d));
int			llist_size(t_llist *llist);
//////////////////////////////TOOLS LLIST\\\\\\\\\\\\\\\\\\\\\\\\\\\/
void	    push_ll(t_llist **dest, t_llist **src);
char		*push_all(t_llist **dest, t_llist **src);
char		*push_bll(t_llist **dest, t_llist **src);

void	    rotate_ll(t_llist **llist);
char		*rotate_all(t_llist **llist);
char		*rotate_bll(t_llist **llist);

void	    rev_rotate_ll(t_llist **llist);
char		*rev_rotate_all(t_llist **llist);
char		*rev_rotate_bll(t_llist **llist);

void	    swap_ll(t_llist *llist);
char		*swap_all(t_llist *llist);
char		*swap_bll(t_llist *llist);
//////////////////////////////TOOLS\\\\\\\\\\\\\\\\\\\\\\\\\\\/
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
char		*push_swap(t_llist **stack);

int			find_max(t_list *a);
int			find_min(t_list *a);
void		del_node(void *tmp);

char	    *sort_b(t_list **a, t_list **b, int min_size);
char	    *arr_sort(t_list **a);
char		*sndtimes(t_llist **a, int scatter);

void	    *make_data(int x);

char	    *trivial_sort(t_llist **llst);

double      scatter(int count);