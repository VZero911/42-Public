/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 03:55:27 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	fill_mq(t_median **mq, int len, int array[])
{
	if (len % 2 == 0)
		(*mq)->med = len / 2;
	(*mq)->q1 = (((*mq)->med) + 1) / 2;
	if ((*mq)->med % 2 == 0)
		(*mq)->q1 = ((*mq)->med) / 2;
	(*mq)->q2 = ((*mq)->med) + ((*mq)->q1);
	if (len > 5)
	{
		(*mq)->q1 = array[(*mq)->q1];
		(*mq)->q2 = array[(*mq)->q2];
	}
	else
	{
		(*mq)->q1 = 0;
		(*mq)->q2 = 0;
	}
}

static void	doublon_and_fill(int array[], int len, t_median **mq)
{
	int	i;
	int	tmp;
	int	l;

	i = 0;
	tmp = array[0];
	l = 1;
	while (++i < len)
	{
		if (array[i] == tmp)
			l = 0;
		tmp = array[i];
	}
	(*mq)->len = len;
	if (!l)
		(*mq)->len = l;
	(*mq)->med = (len + 1) / 2;
	fill_mq(mq, len, array);
}

void	parsing(char **spl, t_median **mq, int *error)
{
	int		len;
	int		i;
	int		*tab;

	len = 0;
	while (spl[len] && spl != NULL)
		++len;
	tab = malloc(sizeof(int) * len);
	if (!tab || !spl)
	{
		(*mq) = NULL;
		return ;
	}
	i = len;
	while (--i != -1)
	{
		tab[i] = ft_atol_and_check(spl[i], error);
		free(spl[i]);
	}
	free(spl);
	quick_sort(tab, 0, len - 1);
	doublon_and_fill(tab, len, mq);
	(*mq)->med = tab[((*mq)->med) - 1];
	free(tab);
}
