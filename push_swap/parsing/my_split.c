/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 01:40:58 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	split_len(char **spl)
{
	int	i;

	i = -1;
	if (!spl)
		return (-1);
	while (spl[++i])
		free(spl[i]);
	free(spl);
	return (i);
}

char	**my_split(int argc, char **argv)
{
	int		i;
	char	**split;

	if (argc > 2)
	{
		i = 0;
		split = malloc(sizeof(char *) * argc);
		while (++i < argc)
		{
			if (split_len(ft_split(argv[i], ' ')) != 1 || !split)
			{
				i++;
				while (--i != 0 || split != NULL)
					free(split[i]);
				free(split);
				return (NULL);
			}
			split[i - 1] = ft_strdup(argv[i]);
		}
		split[argc - 1] = NULL;
		return (split);
	}
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (NULL);
}
