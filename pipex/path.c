/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:09:29 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/29 02:06:25 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_if_execve_fail(char **cmd_args, char *cmd_path)
{
	perror("Execve error");
	ft_free_char_tab(cmd_args);
	free(cmd_path);
	exit(1);
}

char	**parse_command(char *cmd)
{
	return (ft_split(cmd, ' '));
}

char	*find_command_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*full_path;
	int		i;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	paths = ft_split(*envp + 5, ':');
	i = -1;
	while (paths[++i])
	{
		full_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(full_path, cmd);
		free(full_path);
		if (access(path, X_OK) == 0)
		{
			ft_free_char_tab(paths);
			return (path);
		}
		free(path);
	}
	ft_free_char_tab(paths);
	return (NULL);
}
