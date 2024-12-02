/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:13:14 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/03 00:27:44 by marvin           ###   ########.fr       */
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

// void	execute_pipex(t_pipex *pipex, char **argv, char **envp);
void	multiples_pipes(t_pipex *pipex, char **argv, char **envp);
void	cleanup_pipex(t_pipex *pipex);
void	handles_child(t_pipex *pipex, char **argv, char **envp, int i);
void	handle_heredoc(t_pipex *pipex, int argc, char **argv, char **envp);

// int		validate_files(char *input_file, char *output_file);
char	**parse_command(char *cmd);
void	close_all_pipes(t_pipex *pipex);
char	*find_command_path(char *cmd, char **envp);
void	free_if_execve_fail(char **cmd_args, char *cmd_path);
t_pipex	*open_file(t_pipex *pipex, bool fd);

#endif