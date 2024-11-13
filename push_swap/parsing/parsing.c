/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 01:17:48 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	fill_array(int *array, char **split, int *len, int *error)
{
	int	i;
	int	split_len;

	split_len = count_split(split);
	i = 0;
	*len = 0;
	while (i < split_len)
	{
		array[*len] = ft_atol_and_check(split[i], error);
		if (*error)
			return (0);
		(*len)++;
		i++;
	}
	return (1);
}

t_median	*create_mq(int *array, int len)
{
	t_median	*mq;

	mq = malloc(sizeof(t_median));
	if (!mq)
		return (NULL);
	fill_mq(mq, array, len);
	return (mq);
}

int	handle_split(char **split)
{
	if (!split)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	handle_array(int *array, char **split, int error, int len)
{
	if (error || len == 0 || !array)
	{
		free_split_array(split);
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
