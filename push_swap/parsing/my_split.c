/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 00:22:01 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	split_len(char **spl)
{
	int	i;

	if (!spl)
		return (-1);
	i = 0;
	while (spl[i])
		i++;
	return (i);
}

static int	free_split(char **split, int i)
{
	while (--i >= 0)
		free(split[i]);
	free(split);
	return (0);
}

static char	**handle_multi_args(int argc, char **argv)
{
	int		i;
	char	**split;
	char	**temp;

	split = malloc(sizeof(char *) * argc);
	if (!split)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (!temp || split_len(temp) != 1)
		{
			if (temp)
				free_split(temp, split_len(temp));
			free_split(split, i);
			return (NULL);
		}
		free_split(temp, split_len(temp));
		split[i - 1] = ft_strdup(argv[i]);
		if (!split[i - 1])
			return (free_split(split, i), NULL);
	}
	split[argc - 1] = NULL;
	return (split);
}

char	**my_split(int argc, char **argv)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	if (argc > 2)
		return (handle_multi_args(argc, argv));
	return (NULL);
}
