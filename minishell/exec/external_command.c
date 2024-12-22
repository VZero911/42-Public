/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:51:06 by marvin            #+#    #+#             */
/*   Updated: 2024/12/21 07:11:56 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_external_cmd(t_command *cmd, char **argv, t_state *state)
{
	char	*path;
	pid_t	pid;
	int		status;
	char	*exit_str;

	path = get_command_path(argv[0]);
	if (!path)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		state->last_exit_status = 127;
		exit_str = ft_itoa(state->last_exit_status);
		state->envp = set_env_var(state->envp, "EXIT_STATUS", exit_str);
		free(exit_str);
		return ;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		free(path);
		state->last_exit_status = 1;
		exit_str = ft_itoa(state->last_exit_status);
		state->envp = set_env_var(state->envp, "EXIT_STATUS", exit_str);
		free(exit_str);
		return ;
	}
	if (pid == 0)
	{
		if (cmd->infile || cmd->outfile)
			handle_redirections(cmd);
		if (execve(path, argv, state->envp) == -1)
		{
			perror("execve error");
			free(path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			state->last_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			state->last_exit_status = 128 + WTERMSIG(status);
		exit_str = ft_itoa(state->last_exit_status);
		state->envp = set_env_var(state->envp, "EXIT_STATUS", exit_str);
		free(exit_str);
	}
	free(path);
}
