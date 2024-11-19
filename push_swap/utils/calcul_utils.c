/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 00:02:54 by marvin           ###   ########.fr       */
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
