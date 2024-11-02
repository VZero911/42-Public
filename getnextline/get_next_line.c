/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 18:33:39 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update(char *gnl)
{
	size_t	i;
	size_t	j;
	char	*new_gnl;

	i = 0;
	while (gnl[i] && gnl[i] != '\n')
		i++;
	if (!gnl[i])
	{
		free(gnl);
		return (NULL);
	}
	new_gnl = malloc(ft_strlen(gnl) - i + 1);
	if (!new_gnl)
		return (NULL);
	i++;
	j = 0;
	while (gnl[i])
		new_gnl[j++] = gnl[i++];
	new_gnl[j] = '\0';
	free(gnl);
	return (new_gnl);
}

char	*ft_get_line(char *gnl)
{
	int		i;
	char	*line;

	i = 0;
	if (!gnl[i] || !gnl)
		return (NULL);
	i = ft_strlen_gnl(gnl);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (gnl[i] && gnl[i] != '\n')
	{
		line[i] = gnl[i];
		i++;
	}
	if (gnl[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_file(int fd, char *gnl)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(gnl, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(gnl);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		gnl = ft_strjoin_gnl(gnl, buffer);
	}
	free(buffer);
	return (gnl);
}

char	*get_next_line(int fd)
{
	static char	*gnl = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl = ft_read_file(fd, gnl);
	if (!gnl)
		return (NULL);
	line = ft_get_line(gnl);
	gnl = ft_update(gnl);
	return (line);
}
