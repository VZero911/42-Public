/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 05:20:37 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    free_split(char **split)
{
    int i;

    i = 0;
    if (!split)
        return ;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
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

int initialize_stacks(t_stack **stack_a, t_stack **stack_b, char **spl)
{
    int i;
    int len;
    int res;

    *stack_a = NULL;
    *stack_b = NULL;
    if (!spl)
        return (-1);
    len = 0;
    while (spl[len])
        len++;
    i = len;
    while (--i >= 0)
    {
        res = add_to_list(stack_a, ft_atol(spl[i]));
        if (res == -1)
            return (-1);
        free(spl[i]);
    }
    free(spl);
    return (1);
}