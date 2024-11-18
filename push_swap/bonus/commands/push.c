/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/18 22:33:43 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	push_element(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	if ((*src)->next == *src)
	{
		*src = NULL;
	}
	else
	{
		(*src)->prev->next = (*src)->next;
		(*src)->next->prev = (*src)->prev;
		*src = (*src)->next;
	}
	if (add_to_list(dest, tmp->value) == -1)
	{
		free_stack(dest);
		free_stack(src);
		exit(1);
	}
	free(tmp);
}

void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (*stack_b)
	{
		push_element(stack_a, stack_b);
		if (print)
			write(1, "pa\n", 3);
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (*stack_a)
	{
		push_element(stack_b, stack_a);
		if (print)
			write(1, "pb\n", 3);
	}
}
