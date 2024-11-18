/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 01:27:06 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(t_stack **stack_a, t_stack **stack_b, t_median **mq)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(*mq);
}

int	add_to_list(t_stack **stack, int nbr)
{
	t_stack	*node;

	if (new_node(nbr, &node) == -1)
		return (-1);
	if ((*stack) == NULL)
	{
		(*stack) = node;
		(*stack)->next = *stack;
		(*stack)->prev = *stack;
	}
	else
	{
		node->prev = (*stack)->prev;
		node->next = (*stack);
		(*stack)->prev->next = node;
		(*stack)->prev = node;
		(*stack) = node;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if ((*stack) == NULL)
		return ;
	current = (*stack);
	while (current->next != (*stack))
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(current);
	*stack = NULL;
}

int	stack_len(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	if ((stack) && stack->next != stack)
	{
		tmp = (stack)->next;
		i = 1;
		while (tmp != (stack))
		{
			++i;
			tmp = tmp->next;
		}
		return (i);
	}
	return (0);
}

int	new_node(int nbr, t_stack **node)
{
	(*node) = malloc(sizeof(t_stack));
	if (!(*node))
		return (-1);
	(*node)->value = nbr;
	(*node)->next = NULL;
	(*node)->prev = NULL;
	return (1);
}
