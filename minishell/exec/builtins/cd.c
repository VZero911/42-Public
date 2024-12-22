/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:55:58 by marvin            #+#    #+#             */
/*   Updated: 2024/12/12 00:55:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	validate_path(const char *path)
{
	struct stat path_stat;

	if (access(path, F_OK) != 0)
	{
		printf("cd: %s: No such file or directory\n", path);
		return (0);
	}
	if (stat(path, &path_stat) != 0)
	{
		perror("cd: stat error");
		return (0);
	}
	if (!S_ISDIR(path_stat.st_mode))
	{
		printf("cd: %s: Not a directory\n", path);
		return (0);
	}
	return (1);
}

char	*get_cd_path(char **argv)
{
    char	*path;

	if (!argv[1])
	{
		path = getenv("HOME");
		if (!path)
		{
			printf("cd: HOME not set\n");
			return (NULL);
		}
	}
	else
	    path = argv[1];
	return (path);
}

void	update_env_vars(t_state *state, const char *old_path)
{
	if (getcwd(state->current_path, sizeof(state->current_path)) == NULL)
	{
		perror("cd: getcwd error");
		ft_strlcpy(state->current_path, "", 1);
	}
	state->envp = set_env_var(state->envp, "OLDPWD", old_path);
	state->envp = set_env_var(state->envp, "PWD", state->current_path);
	printf("Changed to: %s\n", state->current_path);
}

void	handle_cd_command(char **argv, t_state *state)
{
	char	old_path[1024];
	char	*path;

	path = get_cd_path(argv);
	if (!path)
		return ;
	if (!getcwd(old_path, sizeof(old_path)))
	{
		perror("cd: getcwd error");
		return ;
	}
	if (!validate_path(path))
		return ;
	if (chdir(path) != 0)
	{
		perror("cd: chdir error");
		return ;
	}
	update_env_vars(state, old_path);
}
