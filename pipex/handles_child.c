/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:09:29 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/29 02:12:28 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_first_child(t_pipex *pipex)
{
	if (dup2(pipex->input_fd, STDIN_FILENO) < 0)
	{
		perror("dup2 input error for first child");
		cleanup_pipex(pipex);
		exit(1);
	}
	if (dup2(pipex->pipes[0][WRITE], STDOUT_FILENO) < 0)
	{
		perror("dup2 output error for first child");
		cleanup_pipex(pipex);
		exit(1);
	}
}

void	handle_last_child(t_pipex *pipex)
{
	if (dup2(pipex->pipes[pipex->pipe_count - 1][READ], STDIN_FILENO) < 0)
	{
		perror("dup2 input error for last child");
		cleanup_pipex(pipex);
		exit(1);
	}
	if (dup2(pipex->output_fd, STDOUT_FILENO) < 0)
	{
		perror("dup2 output error for last child");
		cleanup_pipex(pipex);
		exit(1);
	}
}

void	handle_intermediate_child(t_pipex *pipex, int i)
{
	if (dup2(pipex->pipes[i - 1][READ], STDIN_FILENO) < 0)
	{
		perror("dup2 input error for intermediate child");
		cleanup_pipex(pipex);
		exit(1);
	}
	if (dup2(pipex->pipes[i][WRITE], STDOUT_FILENO) < 0)
	{
		perror("dup2 output error for intermediate child");
		cleanup_pipex(pipex);
		exit(1);
	}
}

void	handles_child(t_pipex *pipex, char **argv, char **envp, int i)
{
	if (i == 0)
		handle_first_child(pipex);
	else if (i == pipex->pipe_count)
		handle_last_child(pipex);
	else
		handle_intermediate_child(pipex, i);
	close_all_pipes(pipex);
	pipex->cmd_args = parse_command(argv[2 + i]);
	pipex->cmd_paths = find_command_path(pipex->cmd_args[0], envp);
	if (!pipex->cmd_paths)
	{
		ft_free_char_tab(pipex->cmd_args);
		perror("Command not found");
		exit(127);
	}
	cleanup_pipex(pipex);
	execve(pipex->cmd_paths, pipex->cmd_args, envp);
	perror("Execve error");
	exit(1);
}
