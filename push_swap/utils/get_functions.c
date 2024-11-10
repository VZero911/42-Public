/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 01:54:22 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_index(t_stack *stack, int node)
{
	t_stack		*tmp;
	int			i;

	i = 0;
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->value == node)
			return (i);
		tmp = tmp->next;
		++i;
	}
	return (i);
}

int	get_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	tmp = stack->next;
	min = stack->value;
	while (tmp != stack && tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	tmp = stack->next;
	max = stack->value;
	while (tmp != stack && tmp != NULL)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_pos_to_place(t_stack *stack, int node)
{
	int		min;
	int		i;
	int		l;
	t_stack	*tmp;

	min = get_min(stack);
	if (node > get_max(stack) || node < min)
		return (get_index(stack, min));
	l = stack_len(stack);
	i = -1;
	tmp = stack;
	while (++i < l)
	{
		if (tmp->prev->value < node && node < tmp->value)
			return (i);
		tmp = tmp->next;
	}
	return (0);
}
