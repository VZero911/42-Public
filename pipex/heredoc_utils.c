/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:00:00 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/07 04:40:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_heredoc_resources(t_pipex *pipex)
{
	if (pipex->input_fd != -1)
		close(pipex->input_fd);
	if (pipex->output_fd != -1)
		close(pipex->output_fd);
	free(pipex->heredoc_pipe);
	free(pipex->pid);
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	if (!pipex->heredoc_pipe)
		return ;
	i = 0;
	while (i < pipex->pipe_count * 2)
	{
		if (pipex->heredoc_pipe[i] != -1)
		{
			close(pipex->heredoc_pipe[i]);
			pipex->heredoc_pipe[i] = -1;
		}
		i++;
	}
}

void	heredoc_exit(char *msg_error, char **cmd_args, int exit_code)
{
	ft_putstr_fd(msg_error, 2);
	ft_putstr_fd(cmd_args[0], 2);
	ft_putstr_fd("\n", 2);
	ft_free_char_tab(cmd_args);
	exit(exit_code);
}

void	waitpid_all(t_pipex *pipex)
{
	int	status;
	int	i;

	i = -1;
	while (++i < pipex->pipe_count + 1)
		waitpid(pipex->pid[i], &status, 0);
	cleanup_pipex(pipex);
	free_heredoc_resources(pipex);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		exit(128 + WTERMSIG(status));
}
