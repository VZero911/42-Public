/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 01:15:39 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	has_duplicates(int array[], int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static int	*parse_arguments(char **split, int *len, int *error)
{
	int	*array;
	int	split_len;

	split_len = count_split(split);
	array = create_array(split, split_len);
	if (!array)
		return (NULL);
	if (!fill_array(array, split, len, error))
	{
		free(array);
		return (NULL);
	}
	if (has_duplicates(array, *len))
	{
		free(array);
		*error = 1;
		return (NULL);
	}
	return (array);
}

static void	parsing(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	int			*array;
	t_median	*mq;
	int			len;
	int			error;
	char		**split;

	len = 0;
	error = 0;
	split = my_split(argc, argv);
	if (!handle_split(split))
		return ;
	array = parse_arguments(split, &len, &error);
	if (!handle_array(array, split, error, len))
		return ;
	quick_sort(array, 0, len - 1);
	mq = create_mq(array, len);
	if (!mq)
		check_array_errors(array, split, NULL);
	free(array);
	if (initialize_stacks(stack_a, stack_b, split) == 1)
		start_algo(*stack_a, *stack_b, mq);
	else
		free_split_array(split);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	parsing(argc, argv, &stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
