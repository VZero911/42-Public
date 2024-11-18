/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/18 22:31:26 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// void print_stacks(t_stack *stack_a, t_stack *stack_b)
// {
//     t_stack *current_a;
//     t_stack *current_b;
//     int first_a = 1;
//     int first_b = 1;
//     printf("\n=== Stack State ===\n");
//     // Print Stack A
//     printf("Stack A: ");
//     if (stack_a)
//     {
//         current_a = stack_a;
//         do {
//             if (!first_a)
//                 printf(" -> ");
//             printf("%d", current_a->value);
//             first_a = 0;
//             current_a = current_a->next;
//         } while (current_a != stack_a);
//     }
//     else
//         printf("(empty)");
//     printf("\n");
//     printf("Stack B: ");
//     if (stack_b)
//     {
//         current_b = stack_b;
//         do {
//             if (!first_b)
//                 printf(" -> ");
//             printf("%d", current_b->value);
//             first_b = 0;
//             current_b = current_b->next;
//         } while (current_b != stack_b);
//     }
//     else
//         printf("(empty)");
//     printf("\n================\n\n");
// }

static int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (1);
	if (stack->next == stack)
		return (1);
	current = stack;
	while (current->next != stack)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

static int	execute_operation(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "sa\n"))
		sa(stack_a, 0);
	else if (ft_strcmp(line, "sb\n"))
		sb(stack_b, 0);
	else if (ft_strcmp(line, "ss\n"))
		ss(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "pa\n"))
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "pb\n"))
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "ra\n"))
		ra(stack_a, 0);
	else if (ft_strcmp(line, "rb\n"))
		rb(stack_b, 0);
	else if (ft_strcmp(line, "rr\n"))
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "rra\n"))
		rra(stack_a, 0);
	else if (ft_strcmp(line, "rrb\n"))
		rrb(stack_b, 0);
	else if (ft_strcmp(line, "rrr\n"))
		rrr(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

static void	check_operations(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!execute_operation(line, stack_a, stack_b))
		{
			free(line);
			write(2, "Error\n", 6);
			free_stack(stack_a);
			free_stack(stack_b);
			exit(1);
		}
		free(line);
	}
}

static int	check_duplicates(char **numbers)
{
	int	i;
	int	j;
	int	error;
	int	num1;
	int	num2;

	i = 0;
	while (numbers[i])
	{
		num1 = ft_atol_and_check(numbers[i], &error);
		if (error)
			return (1);
		j = i + 1;
		while (numbers[j])
		{
			num2 = ft_atol_and_check(numbers[j], &error);
			if (error || num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	numbers = my_split(argc, argv);
	if (!numbers || check_duplicates(numbers))
	{
		if (numbers)
			free_split(numbers);
		write(2, "Error\n", 6);
		return (1);
	}
	if (initialize_stacks(&stack_a, &stack_b, numbers) == -1)
		return (write(2, "Error\n", 6), 1);
	check_operations(&stack_a, &stack_b);
	if (!stack_b && is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
