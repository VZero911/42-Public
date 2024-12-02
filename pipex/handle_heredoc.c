/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:15:00 by marvin            #+#    #+#             */
/*   Updated: 2024/12/02 23:15:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_heredoc_resources(t_pipex *pipex)
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
	for (i = 0; i < pipex->pipe_count * 2; i++)
	{
		if (pipex->heredoc_pipe[i] != -1)
		{
			close(pipex->heredoc_pipe[i]);
			pipex->heredoc_pipe[i] = -1;
		}
	}
}

static void	write_heredoc_input(char *limiter)
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
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 && 
			line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, tmp_fd);
		free(line);
	}
	close(tmp_fd);
}
void	execute_cmd(char *cmd_str, char **envp)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd_str, ' ');
	if (!cmd_args)
		exit(1);
	if (!cmd_args[0])
	{
		ft_free_char_tab(cmd_args);
		exit(1);
	}
	if (cmd_args[0][0] == '/' || cmd_args[0][0] == '.')
	{
		cmd_path = cmd_args[0];
	}
	else
	{
		cmd_path = find_command_path(cmd_args[0], envp);
		if (!cmd_path)
		{
			ft_putstr_fd("Command not found: ", 2);
			ft_putstr_fd(cmd_args[0], 2);
			ft_putstr_fd("\n", 2);
			ft_free_char_tab(cmd_args);
			exit(127);
		}
	}
	if (execve(cmd_path, cmd_args, envp) == -1)
	{
		ft_putstr_fd("Error executing command: ", 2);
		ft_putstr_fd(cmd_args[0], 2);
		ft_putstr_fd("\n", 2);
		if (cmd_path != cmd_args[0])
			free(cmd_path);
		ft_free_char_tab(cmd_args);
		exit(126);
	}
}

void	waitpid_all(t_pipex *pipex)
{
	int	status;
	int	i;

	close_all_pipes(pipex);
	for (i = 0; i < pipex->pipe_count + 1; i++)
	{
		waitpid(pipex->pid[i], &status, 0);
	}
	free(pipex->heredoc_pipe);
	cleanup_pipex(pipex);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		exit(128 + WTERMSIG(status));
}

void	handle_heredoc(t_pipex *pipex, int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	i;

	write_heredoc_input(argv[2]);
	pipex->output_fd = open(pipex->output_file, 
		O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (pipex->output_fd == -1)
		exit(1);
	pipex->input_fd = open("/tmp/heredoc_tmp", O_RDONLY);
	if (pipex->input_fd == -1)
		exit(1);
	pipex->heredoc_pipe = malloc(sizeof(int) * (pipex->pipe_count * 2));
	pipex->pid = malloc(sizeof(pid_t) * (pipex->pipe_count + 1));
	if (!pipex->heredoc_pipe || !pipex->pid)
		exit(1);
	if (pipe(pipe_fd) == -1)
		exit(1);
	i = 0;
	pipex->heredoc_pipe[i * 2] = pipe_fd[0];
	pipex->heredoc_pipe[i * 2 + 1] = pipe_fd[1];
	i = -1;
	while (++i < pipex->pipe_count + 1)
	{
		pipex->pid[i] = fork();
		if (pipex->pid[i] == -1)
			exit(1);
		if (pipex->pid[i] == 0)
		{
			if (i == 0)
			{
				dup2(pipex->input_fd, STDIN_FILENO);
				dup2(pipex->heredoc_pipe[1], STDOUT_FILENO);
				close_pipes(pipex);
				execute_cmd(argv[3], envp);
			}
			else if (i == 1)
			{
				dup2(pipex->heredoc_pipe[0], STDIN_FILENO);
				dup2(pipex->output_fd, STDOUT_FILENO);
				close_pipes(pipex);
				if (argc == 5)
					execute_cmd(argv[4 - 1], envp);
				else
					execute_cmd(argv[4], envp);
			}
		}
	}
	close_pipes(pipex);
	waitpid_all(pipex);
	free_heredoc_resources(pipex);
	unlink("/tmp/heredoc_tmp");
}
