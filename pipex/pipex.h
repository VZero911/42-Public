/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:13:14 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/29 02:22:58 by jdumay           ###   ########.fr       */
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
    int     *pid;
    int     pipe_count;
	char	*input_file;
	char	*output_file;
	char	**cmd_paths;
	char	**cmd_args;
	int		pipe_fd[2];
	int		input_fd;
	int		output_fd;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

int		validate_files(char *input_file, char *output_file);
void	execute_pipex(t_pipex *pipex, char **argv, char **envp);

char	**parse_command(char *cmd);
int		open_file(char *file, int flags, mode_t mode);
void	dup_and_close(int old_fd, int new_fd);
char	*find_command_path(char *cmd, char **envp);
void	free_if_execve_fail(char **cmd_args, char *cmd_path);

#endif