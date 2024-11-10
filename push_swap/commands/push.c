/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 02:18:27 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **pile_a, t_stack **pile_b, t_median **mq, int print)
{
	t_stack	*tmp;

	if (add_to_list(pile_a, (*pile_b)->value) == -1)
	{
		free_all(pile_a, pile_b, mq);
		exit(1);
	}
	tmp = (*pile_b);
	(*pile_b)->prev->next = (*pile_b)->next;
	(*pile_b)->next->prev = (*pile_b)->prev;
	(*pile_b) = (*pile_b)->next;
	free(tmp);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **pile_a, t_stack **pile_b, t_median **mq, int print)
{
	t_stack	*tmp;

	if (add_to_list(pile_b, (*pile_a)->value) == -1)
	{
		free_all(pile_a, pile_b, mq);
		exit(1);
	}
	tmp = (*pile_a);
	(*pile_a)->prev->next = (*pile_a)->next;
	(*pile_a)->next->prev = (*pile_a)->prev;
	(*pile_a) = (*pile_a)->next;
	free(tmp);
	if (print)
		write(1, "pb\n", 3);
}
