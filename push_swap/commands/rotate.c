/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 02:18:41 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **pile_a, int print)
{
	if (*pile_a && (*pile_a)->next != *pile_a)
	{
		*pile_a = (*pile_a)->next;
		if (print)
			write(1, "ra\n", 3);
	}
}

void	rb(t_stack **pile_b, int print)
{
	if (*pile_b && (*pile_b)->next != *pile_b)
	{
		*pile_b = (*pile_b)->next;
		if (print)
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b, int print)
{
	if (*a && (*a)->next != *a && *b && (*b)->next != *b)
	{
		ra(a, 0);
		rb(b, 0);
		if (print)
			write(1, "rr\n", 3);
	}
}
