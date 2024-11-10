/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 04:05:51 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_move(t_stack *stack_a, t_stack *stack_b, int elem)
{
	int	count;
	int	index;

	index = get_index(stack_b, elem);
	count = 1;
	if (index > 1 && index > (stack_len(stack_b) / 2))
		count += stack_len(stack_b) - index - 1;
	else if (index > 1 && index <= (stack_len(stack_b) / 2))
		count += index - 1;
	index = get_pos_to_place(stack_a, elem);
	if (index > 1 && index > (stack_len(stack_a) / 2))
		count += stack_len(stack_a) - index - 1;
	else if (index > 1 && index <= (stack_len(stack_a) / 2))
		count += index - 1;
	return (count);
}

int	get_best_move(t_stack *stack_a, t_stack *stack_b)
{
	int		best_move_elem;
	int		move_count;
	int		best_move_count;
	t_stack	*tmp;

	best_move_elem = stack_b->value;
	best_move_count = count_move(stack_a, stack_b, best_move_elem);
	tmp = stack_b->next;
	while (tmp != stack_b && tmp != NULL)
	{
		move_count = count_move(stack_a, stack_b, tmp->value);
		if (move_count < best_move_count)
		{
			best_move_count = move_count;
			best_move_elem = tmp->value;
		}
		tmp = tmp->next;
	}
	return (best_move_elem);
}

void	sort_three(t_stack **stack_a)
{
	int	fst;
	int	scd;
	int	trd;

	fst = (*stack_a)->value;
	scd = (*stack_a)->next->value;
	trd = (*stack_a)->prev->value;
	if ((fst < scd) && (scd > trd) && (fst < trd))
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if ((fst < scd) && (scd > trd) && (fst > trd))
		rra(stack_a, 1);
	else if ((fst > scd) && (scd < trd) && (fst > trd))
		ra(stack_a, 1);
	else if ((fst > scd) && (scd > trd))
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else
		sa(stack_a, 1);
}
