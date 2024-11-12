/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/11 21:21:50 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	start_algo(t_stack *stack_a, t_stack *stack_b, t_median *mq)
{
	if (mq->len == 2)
		if (stack_a->value > stack_a->next->value)
			write(1, "sa\n", 3);
	if (mq->len == 3)
	{
		sort_three(&stack_a);
		free_all(&stack_a, &stack_b, &mq);
		exit(1);
	}
	if (mq->len > 2)
		if (!stack_sorted(stack_a))
			sort_to_b(stack_a, stack_b, mq);
	free_all(&stack_a, &stack_b, &mq);
	exit(1);
}

int	initialize_stacks(t_stack **stack_a, t_stack **stack_b, char **spl)
{
	int	i;
	int	t;

	i = 0;
	*stack_a = NULL;
	*stack_b = NULL;
	if (!spl)
		return (-1);
	while (spl[i])
		i++;
	while (--i >= 0)
	{
		t = add_to_list(stack_a, ft_atol(spl[i]));
		if (t == -1)
			return (-1);
		free(spl[i]);
	}
	free(spl);
	return (1);
}
