/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:23:11 by vboxuser          #+#    #+#             */
/*   Updated: 2024/12/19 02:19:59 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*generate_tmp_filename(void)
{
	char	*filename;
	char	*pid_str;

	pid_str = ft_itoa(getpid());
	if (!pid_str)
		return (NULL);
	filename = ft_strjoin("/tmp/heredoc_", pid_str);
	free(pid_str);
	if (!filename)
		perror("Error generating temporary filename");
	return (filename);
}

int	write_to_tmp_file(int fd, const char *limiter)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, limiter))
			break ;
		if (write(fd, line, ft_strlen(line)) == -1 || write(fd, "\n", 1) == -1)
		{
			perror("Error writing to temporary file");
			free(line);
			return (-1);
		}
		free(line);
	}
	free(line);
	return (0);
}

int	handle_heredoc(t_command *cmd)
{
	int		fd;
	char	*tmp_filename;

	tmp_filename = generate_tmp_filename();
	if (!tmp_filename)
		return (-1);
	fd = open(tmp_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error opening temporary file");
		free(tmp_filename);
		return (-1);
	}
	if (write_to_tmp_file(fd, cmd->limiter) == -1)
	{
		close(fd);
		unlink(tmp_filename);
		free(tmp_filename);
		return (-1);
	}
	close(fd);
	cmd->infile = tmp_filename;
	return (0);
}
