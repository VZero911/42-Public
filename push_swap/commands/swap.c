/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/18 22:26:37 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **stack_a, int print)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (!stack_a || !(*stack_a) || (*stack_a)->next == (*stack_a))
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int print)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (!stack_b || !(*stack_b) || (*stack_b)->next == (*stack_b))
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print)
		write(1, "ss\n", 3);
}
