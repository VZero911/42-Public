/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:46:34 by marvin            #+#    #+#             */
/*   Updated: 2024/12/12 19:46:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_env_command(char **envp)
{
	int	i;

	i = -1;
	if (envp != NULL)
	{
		while (envp[++i] != NULL)
			printf("%s\n", envp[i]);
	}
	else
		printf("No environment variables found.\n");
}

char	**copy_environment(char **envp)
{
	int		i;
	char	**copy;

	i = 0;
	while (envp[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (envp[++i])
	{
		copy[i] = ft_strdup(envp[i]);
		if (!copy[i])
		{
			ft_free_split(envp, i);
			printf("Failed to create envp");
			exit(EXIT_FAILURE);
		}
	}
	copy[i] = NULL;
	return (copy);
}

char	**set_env_var(char **envp, const char *key, const char *value)
{
	int		i;
	size_t	key_len;
	char	*new_entry;
	char	**result;

	if (!key || !value || !envp)
	{
		perror("Invalid arguments to set_env_var");
		return (NULL);
	}
	i = 0;
	key_len = ft_strlen(key);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, key_len) == 0 && envp[i][key_len] == '=')
		{
			replace_env_entry(envp, i, key, value);
			return (envp);
		}
		i++;
	}
	new_entry = join_key_value(key, value);
	if (!new_entry)
	{
		perror("Error adding new environment variable");
		exit(EXIT_FAILURE);
	}
	result = realloc_tab(envp, new_entry);
	if (!new_entry)
	{
		free(new_entry);
		perror("Error updating new environment variable");
		exit(EXIT_FAILURE);
	}
	free(new_entry);
	return (result);
}
