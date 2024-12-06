/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:00:00 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/06 17:56:39 by jdumay           ###   ########.fr       */
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

void	write_heredoc_input(char *limiter)
{
	char	*line;
	int		tmp_fd;

	tmp_fd = open("/tmp/heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp_fd == -1)
		exit(1);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, tmp_fd);
		free(line);
	}
	close(tmp_fd);
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
