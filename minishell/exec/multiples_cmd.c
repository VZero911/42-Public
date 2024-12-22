/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiples_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:29:25 by vboxuser          #+#    #+#             */
/*   Updated: 2024/12/22 03:55:25 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_pipes(int pipefds[][2], int num_pipes)
{
	int	i;

	i = -1;
	while (++i < num_pipes)
	{
		close(pipefds[i][0]);
		close(pipefds[i][1]);
	}
}

void	execute_command(t_command *cmd, int pipefds[][2], t_state *state)
{
	char	**envp;
	char	*path;

	path = get_command_path(cmd->args[0]);
	if (!path)
	{
		close_pipes(pipefds, state->num_pipes);
		free_command_list(cmd);
		exit(1);
	}
	if (state->index > 0)
		dup2(pipefds[state->index - 1][0], STDIN_FILENO);
	if (state->index < state->num_pipes)
		dup2(pipefds[state->index][1], STDOUT_FILENO);
	if (handle_redirections(cmd) == -1)
	{
		free(path);
		close_pipes(pipefds, state->num_pipes);
		free_command_list(cmd);
		exit(EXIT_FAILURE);	
	}
	envp = state->envp;
	close_pipes(pipefds, state->num_pipes);
	if (execve(path, cmd->args, envp) == -1)
	{
		perror(cmd->args[0]);
		free(path);
		free_command_list(cmd);
		exit(127);	
	}
}

void	handle_multiples_pipes(t_command *cmd, t_state *state)
{
	t_command	*current;
	int			pipefds[1024][2];
	int			i = 0;
	pid_t		pid;

	current = cmd;
	while (current && current->is_pipe)
	{
		state->num_pipes++;
		current = current->next;
	}
	current = cmd;
	i = -1;
	while (++i < state->num_pipes)
	{
		if (pipe(pipefds[i]) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}
	state->index = 0;
	while (current)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
			execute_command(current, pipefds, state);
		state->index++;
		current = current->next;
	}
	close_pipes(pipefds, state->num_pipes);
	i = -1;
	while (++i <= state->num_pipes)
		wait(NULL);
}
