/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:09:29 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/02 17:06:44 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_if_execve_fail(char **cmd_args, char *cmd_path)
{
	perror("Execve error");
	ft_free_char_tab(cmd_args);
	free(cmd_path);
	exit(1);
}

char	**parse_command(char *cmd)
{
	return (ft_split(cmd, ' '));
}

char	*find_command_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*full_path;
	int		i;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	paths = ft_split(*envp + 5, ':');
	i = -1;
	while (paths[++i])
	{
		full_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(full_path, cmd);
		free(full_path);
		if (access(path, X_OK) == 0)
		{
			ft_free_char_tab(paths);
			return (path);
		}
		free(path);
	}
	ft_free_char_tab(paths);
	return (NULL);
}

t_pipex	*open_file(t_pipex *pipex, bool fd)
{
	pipex->input_fd = -1;
    pipex->output_fd = -1;
	pipex->input_fd = open(pipex->input_file, O_RDONLY);
	if (pipex->input_fd < 0 && fd == true)
	{
		close_all_pipes(pipex);
		cleanup_pipex(pipex);
		perror("Error opening input file");
		exit(1);
	}
	pipex->output_fd
		= open(pipex->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->output_fd < 0 && fd == false)
	{
		close_all_pipes(pipex);
		cleanup_pipex(pipex);
		perror("Error opening output file");
		exit(1);
	}
	return (pipex);
}

// int	validate_files(char *input_file, char *output_file)
// {
// 	int	input_fd;
// 	int	output_fd;

// 	input_fd = open(input_file, O_RDONLY);
// 	if (input_fd < 0)
// 	{
// 		perror("Error opening input file");
// 		return (-1);
// 	}
// 	close(input_fd);
// 	output_fd = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	if (output_fd < 0)
// 	{
// 		perror("Error opening/creating output file");
// 		return (-1);
// 	}
// 	close(output_fd);
// 	return (0);
// }
