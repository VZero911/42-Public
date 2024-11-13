/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 03:58:43 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ra(t_stack **stack_a, int print)
{
	if (*stack_a && (*stack_a)->next != *stack_a)
	{
		*stack_a = (*stack_a)->next;
		if (print)
			write(1, "ra\n", 3);
	}
}

void	rb(t_stack **stack_b, int print)
{
	if (*stack_b && (*stack_b)->next != *stack_b)
	{
		*stack_b = (*stack_b)->next;
		if (print)
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b, int print)
{
	if (*a && (*a)->next != *a && *b && (*b)->next != *b)
	{
		ra(a, 0);
		rb(b, 0);
		if (print)
			write(1, "rr\n", 3);
	}
}
