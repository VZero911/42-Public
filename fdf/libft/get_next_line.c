/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:07:59 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/19 04:20:21 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*prepare_line(char **stash, char *newline, size_t len)
{
	char	*line;
	char	*temp;

	line = malloc(len + 1);
	if (!line)
		return (free_and_return(stash));
	ft_memcpy_gnl(line, *stash, len);
	line[len] = '\0';
	temp = NULL;
	if (newline && *(newline + 1))
		temp = ft_strdup_gnl(newline + 1);
	free(*stash);
	*stash = temp;
	return (line);
}

static char	*extract_line(char **stash)
{
	char	*newline;
	size_t	len;

	if (!*stash || !**stash)
		return (free_and_return(stash));
	newline = ft_strchr_gnl(*stash, '\n');
	if (newline)
		len = (size_t)(newline - *stash + 1);
	else
		len = ft_strlen_gnl(*stash);
	return (prepare_line(stash, newline, len));
}

static char	*join_buffer(char *stash, char *buffer, size_t buff_size)
{
	char	*new_stash;
	size_t	s_len;
	size_t	total_len;

	s_len = ft_strlen_gnl(stash);
	total_len = s_len + buff_size;
	new_stash = malloc(total_len + 1);
	if (!new_stash)
		return (free_and_return(&stash));
	if (stash)
		ft_memcpy_gnl(new_stash, stash, s_len);
	ft_memcpy_gnl(new_stash + s_len, buffer, buff_size);
	new_stash[total_len] = '\0';
	free(stash);
	return (new_stash);
}

static char	*read_and_join(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes;
	char	*line;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		*stash = join_buffer(*stash, buffer, bytes);
		if (!*stash || ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	line = extract_line(stash);
	if (!line || bytes <= 0)
		free_and_return(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024] = {0};
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
	{
		if (fd >= 0 && fd < 1024)
			free_and_return(&stash[fd]);
		return (NULL);
	}
	if (stash[fd] && ft_strchr_gnl(stash[fd], '\n'))
	{
		line = extract_line(&stash[fd]);
		if (!stash[fd])
			free_and_return(&stash[fd]);
		return (line);
	}
	return (read_and_join(fd, &stash[fd]));
}
