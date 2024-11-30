/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:09:29 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/30 05:01:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd1(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->input_fd, STDIN_FILENO);
	close(pipex->input_fd);
	dup2(pipex->pipe_fd[WRITE], STDOUT_FILENO);
	close(pipex->pipe_fd[READ]);
	close(pipex->pipe_fd[WRITE]);
	pipex->cmd_args = parse_command(argv[2]);
	if (!pipex->cmd_args)
	{
		perror("Malloc Error");
		cleanup_pipex(pipex);
		exit(1);
	}
	pipex->cmd_paths = find_command_path(pipex->cmd_args[0], envp);
	if (!pipex->cmd_paths)
	{
		cleanup_pipex(pipex);
		perror("Command not found");
		exit(127);
	}
	if (execve(pipex->cmd_paths, pipex->cmd_args, envp) == -1)
		free_if_execve_fail(pipex->cmd_args, pipex->cmd_paths);
}

void	execute_cmd2(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->pipe_fd[READ], STDIN_FILENO);
	close(pipex->pipe_fd[WRITE]);
	close(pipex->pipe_fd[READ]);
	dup2(pipex->output_fd, STDOUT_FILENO);
	close(pipex->output_fd);
	pipex->cmd_args = parse_command(argv[3]);
	if (!pipex->cmd_args)
	{
		cleanup_pipex(pipex);
		perror("Malloc Error");
		exit(1);
	}
	pipex->cmd_paths = find_command_path(pipex->cmd_args[0], envp);
	if (!pipex->cmd_paths)
	{
		cleanup_pipex(pipex);
		perror("Command not found");
		exit(127);
	}
	if (execve(pipex->cmd_paths, pipex->cmd_args, envp) == -1)
		free_if_execve_fail(pipex->cmd_args, pipex->cmd_paths);
}

void	execute_pipex(t_pipex *pipex, char **argv, char **envp)
{
	if (pipe(pipex->pipe_fd) < 0)
	{
		perror("Pipe error");
		exit(1);
	}
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
	{
		perror("Fork error");
		exit(1);
	}
	if (pipex->pid1 == 0)
		execute_cmd1(pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
	{
		perror("Fork error");
		exit(1);
	}
	if (pipex->pid2 == 0)
		execute_cmd2(pipex, argv, envp);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}
