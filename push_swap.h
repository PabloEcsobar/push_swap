/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:55:34 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/22 15:44:57 by polenyc          ###   ########.fr       */
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

//////////////////////////////TOOLS\\\\\\\\\\\\\\\\\\\\\\\\\\\/
void	push(t_list **dest, t_list **src);
char	*push_a(t_list **dest, t_list **src);
char	*push_b(t_list **dest, t_list **src);

void	swap_tl(t_list *stack);
char	*swap_a(t_list *stack);
char	*swap_b(t_list *stack);

void	rotate(t_list **stack);
char	*rotate_a(t_list **stack);
char	*rotate_b(t_list **stack);

void	rev_rotate(t_list **stack);
char	*rev_rotate_a(t_list **stack);
char	*rev_rotate_b(t_list **stack);

char	*element_sort(t_list **stack);
