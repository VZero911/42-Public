/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 02:33:05 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void print_stack(t_stack *stack)
// {
//     t_stack *current = stack;
//     if (!stack)
//     {
//         printf("La pile est vide\n");
//         return;
//     }
//     do {
//         printf("%d -> ", current->value);
//         current = current->next;
//     } while (current != stack);
// 	do {
//         printf("%d -> ", current->value);
//         current = current->prev;
//     } while (current != stack);
//     printf("(retour au sommet)\n");
// }

int	main(int argc, char **argv)
{
	t_median	*mq;
	int			error;
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc == 1)
		exit(1);
	mq = malloc(sizeof(t_median));
	if (!mq)
		return (1);
	error = 0;
	parsing(my_split(argc, argv), &mq, &error);
	if (error || mq->len == 0 || !mq)
	{
		write(2, "Error\n", 6);
		if (mq)
			free(mq);
		return (1);
	}
	if (initialize_pile(&stack_a, &stack_b, my_split(argc, argv)) == 1)
		start_algo(stack_a, stack_b, mq);
	free_stack(&stack_a);
	free(mq);
	return (0);
}
