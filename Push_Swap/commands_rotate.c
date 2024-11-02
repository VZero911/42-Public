/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/31 05:52:22 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_stack_node **stack)
{
    t_stack_node *first;
    t_stack_node *last;

    if (!(*stack) || !((*stack)->next))
        return;

    first = *stack;
    *stack = first->next;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
}
void    pa(t_stack_node **b, t_stack_node **a)
{
    push(b,a);
    write(1, "pa\n", 3);
}