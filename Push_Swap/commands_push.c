/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 20:18:58 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_stack_node **src, t_stack_node **dst)
{
    t_stack_node *temp;

    if (!(*src))
        return;
    temp = *src;
    *src = (*src)->next;
    temp->next = *src;
    *dst = temp;
}

void    pa(t_stack_node **b, t_stack_node **a)
{
    push(b,a);
    write(1, "pa\n", 3);
}
void    pb(t_stack_node **b, t_stack_node **a)
{
    push(b,a);
    write(1, "pb\n", 3);
}