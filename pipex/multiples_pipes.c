/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:09:29 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/30 02:12:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void cleanup_pipex(t_pipex *pipex)
{
	if (!pipex)
		return ;
    if (pipex->pipes)
	{
        ft_free_int_tab(pipex->pipes, pipex->pipe_count);
	}
    if (pipex->pid)
	{
        free(pipex->pid);
	}
	if (pipex->input_fd != -1)
	{
		close(pipex->input_fd);
		pipex->input_fd = -1;
	}
	if (pipex->output_fd != -1)
	{
		close(pipex->output_fd);
		pipex->output_fd = -1;
	}
}

void	close_all_pipes(t_pipex *pipex)
{
    int	i;

	if (!pipex || !pipex->pipes)
		return ;
	i = -1;
	while (++i < pipex->pipe_count)
	{
		if (pipex->pipes[i][0] != -1)
		{
			close(pipex->pipes[i][0]);
			pipex->pipes[i][0] = -1;
		}
		if (pipex->pipes[i][1] != -1)
		{
			close(pipex->pipes[i][1]);
			pipex->pipes[i][1] = -1;
		}
	}
}

pid_t	*create_pid(t_pipex *pipex)
{
	pid_t	*pid;

	pid = (pid_t *)malloc(sizeof(pid_t) * (pipex->pipe_count + 1));
	if (!pid)
	{
		ft_free_int_tab(pipex->pipes, pipex->pipe_count);
		perror("Malloc error for PID array");
		exit(1);
	}
	return (pid);
}

int	**creates_pipes(t_pipex *pipex)
{
	int	**pipes;
	int	i;

	pipes = (int **)malloc(sizeof(int *) * pipex->pipe_count);
	if (!pipes)
		return (perror("Malloc error"), NULL);
	i = -1;
	while (++i < pipex->pipe_count)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipes[i])
		{
			ft_free_int_tab(pipes, i);
			perror("Malloc error");
			exit(1);
		}
		if (pipe(pipes[i]) < 0)
		{
			ft_free_int_tab(pipes, i + 1);
			perror("Pipe error");
			exit(1);
		}
	}
	return (pipes);
}

void	multiples_pipes(t_pipex *pipex, char **argv, char **envp)
{
	int	i;

	pipex->pipes = creates_pipes(pipex);
	pipex->pid = create_pid(pipex);
	if (!pipex->pipes || !pipex->pid)
		return (cleanup_pipex(pipex));
	i = -1;
	while (++i <= pipex->pipe_count)
	{
		pipex->pid[i] = fork();
		if (pipex->pid[i] < 0)
		{
			perror("Fork error");
			cleanup_pipex(pipex);
			exit(1);
		}
		if (pipex->pid[i] == 0)
			handles_child(pipex, argv, envp, i);
	}
	close_all_pipes(pipex);
	i = -1;
	while (++i <= pipex->pipe_count)
		waitpid(pipex->pid[i], NULL, 0);
	cleanup_pipex(pipex);
}
