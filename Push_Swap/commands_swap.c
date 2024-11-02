/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 20:43:24 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack_node **stack)
{
    t_stack_node *first;
    t_stack_node *second;

    if (!(*stack) || !((*stack)->next))
        return;

    first = *stack;
    second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void    sa(t_stack_node **a)
{
    swap(a);
    write(1, "sa\n", 3);    
}

void    sb(t_stack_node **b)
{
    swap(b);
    write(1, "sb\n", 3);    
}