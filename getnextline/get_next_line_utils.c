/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 18:31:20 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	i = 0;
	len = ft_strlen(s) + 1;
	ptr = malloc(len);
	if (ptr)
	{
		while (i < len)
		{
			ptr[i] = s[i];
			i++;
		}
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}
