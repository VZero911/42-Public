/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:13:14 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/06 17:41:38 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define WRITE 1
# define READ 0

typedef struct s_pipex
{
	pid_t	*pid;
	int		pipe_count;
	int		**pipes;
	int		*heredoc_pipe;
	char	*input_file;
	char	*output_file;
	char	*cmd_paths;
	char	**cmd_args;
	int		pipe_fd[2];
	int		input_fd;
	int		output_fd;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

void	multiples_pipes(t_pipex *pipex, char **argv, char **envp);
void	cleanup_pipex(t_pipex *pipex);
void	handles_child(t_pipex *pipex, char **argv, char **envp, int i);
void	handle_heredoc(t_pipex *pipex, int argc, char **argv, char **envp);

char	**parse_command(char *cmd);
void	close_all_pipes(t_pipex *pipex);
char	*find_command_path(char *cmd, char **envp);
void	free_if_execve_fail(char **cmd_args, char *cmd_path);
t_pipex	*open_file(t_pipex *pipex, bool is_input);

void	free_heredoc_resources(t_pipex *pipex);
void	close_pipes(t_pipex *pipex);
void	write_heredoc_input(char *limiter);
void	waitpid_all(t_pipex *pipex);

#endif