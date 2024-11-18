/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 01:04:23 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **stack_a, int print)
{
	if (*stack_a && (*stack_a)->prev != *stack_a)
	{
		*stack_a = (*stack_a)->prev;
		if (print)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **stack_b, int print)
{
	if (*stack_b && (*stack_b)->prev != *stack_b)
	{
		*stack_b = (*stack_b)->prev;
		if (print)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **p_a, t_stack **p_b, int print)
{
	if (*p_a && (*p_a)->prev != *p_a && *p_b && (*p_b)->prev != *p_b)
	{
		rra(p_a, 0);
		rrb(p_b, 0);
		if (print)
			write(1, "rrr\n", 4);
	}
}
