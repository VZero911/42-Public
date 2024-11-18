/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 05:23:30 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_element(t_stack **dest, t_stack **src, t_median **mq)
{
	t_stack	*tmp;

	if (add_to_list(dest, (*src)->value) == -1)
	{
		free_all(dest, src, mq);
		exit(1);
	}
	tmp = *src;
	(*src)->prev->next = (*src)->next;
	(*src)->next->prev = (*src)->prev;
	*src = (*src)->next;
	free(tmp);
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_median **mq, int print)
{
	push_element(stack_a, stack_b, mq);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_median **mq, int print)
{
	push_element(stack_b, stack_a, mq);
	if (print)
		write(1, "pb\n", 3);
}
