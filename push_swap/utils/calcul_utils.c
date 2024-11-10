/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 01:55:08 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_sorted(t_stack *stack)
{
	int	i;
	int	length;

	length = stack_len(stack);
	if (length > 0)
	{
		i = 1;
		while (i++ < length)
		{
			if (stack->value > stack->next->value)
				return (0);
			stack = stack->next;
		}
		return (1);
	}
	return (0);
}

int	inner(t_stack *stack, int q1, int q2)
{
	t_stack	*tmp;
	int		length;
	int		i;

	length = stack_len(stack);
	i = 0;
	tmp = stack;
	while (i < length)
	{
		if (q1 <= tmp->value && tmp->value <= q2)
			return (1);
		tmp = tmp->next;
		++i;
	}
	return (0);
}

void	replace_stack(t_stack **stack)
{
	int		m;
	int		index;
	t_stack	*stack_a;

	stack_a = *stack;
	m = get_min(stack_a);
	if (stack_a->value != m)
	{
		index = get_index(stack_a, m);
		if (index <= stack_len(stack_a) / 2)
			while (stack_a->value != m)
				ra(&stack_a, 1);
		else
			while (stack_a->value != m)
				rra(&stack_a, 1);
	}
	(*stack) = stack_a;
}
