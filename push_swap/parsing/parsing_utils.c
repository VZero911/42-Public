/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 01:18:28 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_split(char **split)
{
	int	i;

	if (!split)
		return (0);
	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	free_split_array(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	check_array_errors(int *array, char **split, t_median *mq)
{
	free_split_array(split);
	free(array);
	if (mq)
		free(mq);
	return (0);
}

int	*create_array(char **split, int split_len)
{
	int	*array;

	if (!split)
		return (NULL);
	array = malloc(sizeof(int) * split_len);
	if (!array)
		return (NULL);
	return (array);
}

void	fill_mq(t_median *mq, int *array, int len)
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
