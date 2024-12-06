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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:00:00 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/05 00:00:00 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	heredoc_exit(char *msg_error, char **cmd_args, int error_code)
{
	ft_putstr_fd(msg_error, 2);
	ft_putstr_fd(cmd_args[0], 2);
	ft_putstr_fd("\n", 2);
	ft_free_char_tab(cmd_args);
	exit(error_code);
}

static void	execute_cmd(char *cmd_str, char **envp)
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
		cmd_path = cmd_args[0];
	else
	{
		cmd_path = find_command_path(cmd_args[0], envp);
		if (!cmd_path)
			heredoc_exit("Command not found: ", cmd_args, 126);
	}
	if (execve(cmd_path, cmd_args, envp) == -1)
	{
		if (cmd_path != cmd_args[0])
			free(cmd_path);
		heredoc_exit("Error executing command: ", cmd_args, 127);
	}
}

static void	heredoc_child_process(t_pipex *pipex, char **argv,
			char **envp, int i)
{
	if (i == 0)
	{
		dup2(pipex->input_fd, STDIN_FILENO);
		dup2(pipex->heredoc_pipe[WRITE], STDOUT_FILENO);
	}
	else
	{
		dup2(pipex->heredoc_pipe[READ], STDIN_FILENO);
		dup2(pipex->output_fd, STDOUT_FILENO);
	}
	close_pipes(pipex);
	free_heredoc_resources(pipex);
	execute_cmd(argv[i + 3], envp);
}

static void	create_pipes_and_fork(t_pipex *pipex, int argc,
			char **argv, char **envp)
{
	int	i;

	i = 0;
	while (i < pipex->pipe_count + 1)
	{
		pipex->pid[i] = fork();
		if (pipex->pid[i] == -1)
			exit(1);
		if (pipex->pid[i] == 0)
		{
			if (argc == 5)
				heredoc_child_process(pipex, argv - 1, envp, i);
			else
				heredoc_child_process(pipex, argv, envp, i);
		}
		i++;
	}
}

void	handle_heredoc(t_pipex *pipex, int argc, char **argv, char **envp)
{
	int	pipe_fd[2];

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
	if (!pipex->heredoc_pipe || !pipex->pid || pipe(pipe_fd) == -1)
		exit(1);
	pipex->heredoc_pipe[WRITE] = pipe_fd[1];
	pipex->heredoc_pipe[READ] = pipe_fd[0];
	create_pipes_and_fork(pipex, argc, argv, envp);
	close_pipes(pipex);
	waitpid_all(pipex);
	unlink("/tmp/heredoc_tmp");
}
