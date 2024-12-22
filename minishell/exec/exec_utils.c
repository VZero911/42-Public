/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:40:35 by vboxuser          #+#    #+#             */
/*   Updated: 2024/12/22 02:07:15 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*try_paths(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*full;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (NULL);
		full = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!full)
			return (NULL);
		if (access(full, X_OK) == 0)
			return (ft_free_array(paths), full);
		free(full);
		i++;
	}
	return (ft_free_array(paths), NULL);
}

char	*get_command_path(char *cmd)
{
	char	**paths;
	char	*path_env;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	return (try_paths(paths, cmd));
}
