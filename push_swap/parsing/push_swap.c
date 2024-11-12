/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/11 21:13:16 by jdumay           ###   ########.fr       */
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

static int	*parse_arguments(int argc, char **argv, int *len, int *error)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * (argc - 1));
	if (!array)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		array[*len] = ft_atol_and_check(argv[i], error);
		if (*error)
		{
			free(array);
			return (NULL);
		}
		(*len)++;
		i++;
	}
	if (has_duplicates(array, *len))
	{
		free(array);
		*error = 1;
		return (NULL);
	}
	return (array);
}

static void	fill_mq(t_median *mq, int *array, int len)
{
	mq->len = len;
	mq->med = (len + 1) / 2;
	mq->quartile1 = (mq->med + 1) / 2;
	if (mq->med % 2 == 0)
		mq->quartile1 = mq->med / 2;
	mq->quartile3 = mq->med + mq->quartile1;
	if (len > 5)
	{
		mq->quartile1 = array[mq->quartile1 - 1];
		mq->quartile3 = array[mq->quartile3 - 1];
	}
	else
	{
		mq->quartile1 = 0;
		mq->quartile3 = 0;
	}
	mq->med = array[mq->med - 1];
}

static void	parsing(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	int			*array;
	t_median	*mq;
	int			len;
	int			error;

	len = 0;
	error = 0;
	array = parse_arguments(argc, argv, &len, &error);
	if (error || len == 0 || !array)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	quick_sort(array, 0, len - 1);
	mq = malloc(sizeof(t_median));
	if (!mq)
	{
		free(array);
		return ;
	}
	fill_mq(mq, array, len);
	free(array);
	if (initialize_stacks(stack_a, stack_b, my_split(argc, argv)) == 1)
		start_algo(*stack_a, *stack_b, mq);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc == 1)
		return (1);
	parsing(argc, argv, &stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
