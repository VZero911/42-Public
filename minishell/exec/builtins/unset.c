/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:09:25 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 21:09:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_unset_command(char **argv, char **envp)
{
	int		i;
	int		j;
	char	*key;
	size_t	key_len;

	i = 1;
	if (!argv[1])
	{
		printf("unset: not enough arguments\n");
		return ;
	}
	while (argv[i])
	{
		key = argv[i];
		key_len = ft_strlen(key);
		j = 0;
		while (envp[j] != NULL)
		{
			if (ft_strncmp(envp[j], key, key_len) == 0
				&& envp[j][key_len] == '=')
			{
				free(envp[j]);
				while (envp[j + 1] != NULL)
				{
					envp[j] = envp[j + 1];
					j++;
				}
				envp[j] = NULL;
				break ;
			}
			j++;
		}
		i++;
	}
}
