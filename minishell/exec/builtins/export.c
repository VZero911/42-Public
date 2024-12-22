/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:08:27 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 21:08:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_export_command(char **argv, t_state *state)
{
	int		i;
	char	*key;
	char	*value;
	char	*equal_sign;
	int		key_len;

	i = 1;
	if (!argv[1])
		return (handle_env_command(state->envp));
	while (argv[i])
	{
		key = NULL;
		value = NULL;
		equal_sign = ft_strchr(argv[i], '=');
		if (equal_sign)
		{
			key_len = equal_sign - argv[i];
			key = malloc(key_len + 1);
			if (!key)
			{
				perror("malloc");
				return ;
			}
			ft_strlcpy(key, argv[i], key_len + 1);
			value = ft_strdup(equal_sign + 1);
			if (!value)
			{
				perror("malloc");
				free(key);
				return ;
			}
			state->envp = set_env_var(state->envp, key, value);
			free(key);
			free(value);
		}
		else
			printf("export: invalid format: '%s'\n", argv[i]);
		i++;
	}
}
