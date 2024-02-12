/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:05:57 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/12 15:00:31 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/push_swap.h"

int main(int argc, char **argv)
{
    t_llist *a;
    t_llist *b;

    a = NULL;
    b = NULL;
    pushswapapp(&a, &b, argc, argv);
    return (0);
}