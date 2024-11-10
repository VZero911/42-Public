/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 04:05:32 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static
int	check_for_opti(t_stack **stack_a, t_stack **stack_b, int pos_a, int pos_b)
{
	int	i;
	int	length_a;
	int	length_b;

	i = 0;
	length_a = stack_len(*stack_a);
	length_b = stack_len(*stack_b);
	if ((pos_a <= (length_a / 2)) && (pos_b <= (length_b / 2)))
	{
		while (i <= (pos_a - 1) && i <= (pos_b - 1))
		{
			rr(stack_a, stack_b, 1);
			i++;
		}
	}
	if ((pos_a > (length_a / 2)) && (pos_b > (length_b / 2)))
	{
		while (i < (length_a - pos_a) && i < (length_b - pos_b))
		{
			rrr(stack_a, stack_b, 1);
			i++;
		}
	}
	return (i);
}

static t_stack	*rr_rra(t_stack *stack_a, int pos_a, int i)
{
	if (pos_a <= (stack_len(stack_a) / 2))
	{
		while (i <= pos_a - 1)
		{
			ra(&stack_a, 1);
			++i;
		}
	}
	else
	{
		while (i < (stack_len(stack_a) - pos_a))
		{
			rra(&stack_a, 1);
			++i;
		}
	}
	return (stack_a);
}

void	insertion_sort(t_stack **p_a, t_stack **p_b, int b_move, t_median **mq)
{
	int	pos_a;
	int	pos_b;
	int	i;

	pos_a = get_pos_to_place((*p_a), b_move);
	pos_b = get_index((*p_b), b_move);
	i = check_for_opti(p_a, p_b, pos_a, pos_b);
	while ((*p_b)->value != b_move)
	{
		if (pos_b <= (stack_len((*p_b)) / 2))
			rb(p_b, 1);
		else
			rrb(p_b, 1);
	}
	(*p_a) = rr_rra((*p_a), pos_a, i);
	pa(p_a, p_b, mq, 1);
}

void	push_a_optimize(t_stack *stack_a, t_stack *stack_b, t_median *mq)
{
	mq->len -= 3;
	while (mq->len)
	{
		insertion_sort(&stack_a, &stack_b,
			get_best_move(stack_a, stack_b), &mq);
		mq->len--;
	}
	replace_stack(&stack_a);
	stack_b = NULL;
	free_all(&stack_a, &stack_b, &mq);
	exit(1);
}

void	push_b_optimize(t_stack *stack_a, t_stack *stack_b, t_median *mq)
{
	while (inner(stack_a, mq->q1, mq->q2) && mq->len >= 8)
	{
		if (stack_a->value >= mq->q1 && stack_a->value <= mq->med)
		{
			pb(&stack_a, &stack_b, &mq, 1);
			rb(&stack_b, 1);
			continue ;
		}
		if (stack_a->value <= mq->q2 && stack_a->value >= mq->med)
		{
			pb(&stack_a, &stack_b, &mq, 1);
			continue ;
		}
		else
			ra(&stack_a, 1);
	}
	while (stack_len(stack_a) > 3)
	{
		pb(&stack_a, &stack_b, &mq, 1);
		if (stack_b->value < mq->med)
			rb(&stack_b, 1);
	}
	if (!(stack_sorted(stack_a)))
		sort_three(&stack_a);
	push_a_optimize(stack_a, stack_b, mq);
}
