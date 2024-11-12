/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/11 21:21:37 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	optimize_rotations(t_stack **stack_a, t_stack **stack_b,
					int pos_a, int pos_b)
{
	int	rotations;
	int	len_a;
	int	len_b;

	rotations = 0;
	len_a = stack_len(*stack_a);
	len_b = stack_len(*stack_b);
	if (pos_a <= len_a / 2 && pos_b <= len_b / 2)
	{
		while (rotations < pos_a && rotations < pos_b)
		{
			rr(stack_a, stack_b, 1);
			rotations++;
		}
	}
	else if (pos_a > len_a / 2 && pos_b > len_b / 2)
	{
		while (rotations < (len_a - pos_a) && rotations < (len_b - pos_b))
		{
			rrr(stack_a, stack_b, 1);
			rotations++;
		}
	}
	return (rotations);
}

static t_stack	*rotate_stack_a(t_stack *stack_a,
					int target_pos, int done_rotations)
{
	int	len;

	len = stack_len(stack_a);
	if (target_pos <= len / 2)
	{
		while (done_rotations < target_pos)
		{
			ra(&stack_a, 1);
			done_rotations++;
		}
	}
	else
	{
		while (done_rotations < (len - target_pos))
		{
			rra(&stack_a, 1);
			done_rotations++;
		}
	}
	return (stack_a);
}

static void	move_to_a(t_stack **a, t_stack **b,
					int value_to_move, t_median **mq)
{
	int	pos_in_a;
	int	pos_in_b;
	int	done_rotations;

	pos_in_a = get_pos_to_place((*a), value_to_move);
	pos_in_b = get_index((*b), value_to_move);
	done_rotations = optimize_rotations(a, b, pos_in_a, pos_in_b);
	while ((*b)->value != value_to_move)
	{
		if (pos_in_b <= stack_len((*b)) / 2)
			rb(b, 1);
		else
			rrb(b, 1);
	}
	*a = rotate_stack_a(*a, pos_in_a, done_rotations);
	pa(a, b, mq, 1);
}

void	sort_back_to_a(t_stack *stack_a, t_stack *stack_b, t_median *mq)
{
	mq->len -= 3;
	while (mq->len)
	{
		move_to_a(&stack_a, &stack_b,
			get_best_move(stack_a, stack_b), &mq);
		mq->len--;
	}
	replace_stack(&stack_a);
	stack_b = NULL;
	free_all(&stack_a, &stack_b, &mq);
	exit(1);
}

void	sort_to_b(t_stack *stack_a, t_stack *stack_b, t_median *mq)
{
	while (inner(stack_a, mq->quartile1, mq->quartile3) && mq->len >= 8)
	{
		if (stack_a->value >= mq->quartile1 && stack_a->value <= mq->med)
		{
			pb(&stack_a, &stack_b, &mq, 1);
			rb(&stack_b, 1);
		}
		else if (stack_a->value <= mq->quartile3 && stack_a->value >= mq->med)
			pb(&stack_a, &stack_b, &mq, 1);
		else
			ra(&stack_a, 1);
	}
	while (stack_len(stack_a) > 3)
	{
		pb(&stack_a, &stack_b, &mq, 1);
		if (stack_b->value < mq->med)
			rb(&stack_b, 1);
	}
	if (!stack_sorted(stack_a))
		sort_three(&stack_a);
	sort_back_to_a(stack_a, stack_b, mq);
}
