/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:23:50 by marvin            #+#    #+#             */
/*   Updated: 2024/12/19 09:27:50 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*join_key_value(const char *key, const char *value)
{
	char	*temp;
	char	*result;

	if (!key || !value)
	{
		perror("Invalid key or value for environment variable");
		return (NULL);
	}
	temp = ft_strjoin(key, "=");
	if (!temp)
	{
		perror("Failed to allocate memory for key=value");
		return (NULL);
	}
	result = ft_strjoin(temp, value);
	free(temp);
	if (!result)
		perror("Failed to allocate memory for key=value");
	return (result);
}

void	replace_env_entry(char **envp, int index, const char *key,
	const char *value)
{
	char	*new_entry;

	new_entry = join_key_value(key, value);
	if (!new_entry)
	{
		perror("Error updating environment variable");
		exit(EXIT_FAILURE);
	}
	free(envp[index]);
	envp[index] = new_entry;
}

char	**realloc_tab(char **envp, const char *new_entry)
{
	int		count;
	int		i;
	char	**new_envp;

	count = 0;
	while (envp[count])
		count++;
	new_envp = malloc((count + 2) * sizeof(char *));
	if (!new_envp)
	{
		perror("Error reallocating environment variable array");
		return (NULL);
	}
	i = -1;
	while (++i < count)
		new_envp[i] = envp[i];
	new_envp[count] = ft_strdup(new_entry);
	if (!new_envp[count])
	{
		perror("Error duplicating new environment variable");
		new_envp[count] = NULL;
		return (free(new_envp), NULL);
	}
	new_envp[count + 1] = NULL;
	return (free(envp), new_envp);
}
