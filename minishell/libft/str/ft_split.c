/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 22:45:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_next_split(char const *s, char c)
{
	while (*s && *s != c)
		s++;
	return ((char *)s);
}

static size_t	ft_count(char const *s, char c)
{
	size_t	count;
	char	*current;

	count = 0;
	while (*s)
	{
		current = ft_next_split(s, c);
		if (current > s)
			count++;
		if (*current == '\0')
			break ;
		s = current + 1;
	}
	return (count);
}

static int	ft_split_word(char **split, char const *s, char c, size_t count)
{
	size_t	i;
	char	*current;

	i = 0;
	while (i < count)
	{
		current = ft_next_split(s, c);
		if (current > s)
		{
			split[i] = ft_substr(s, 0, current - s);
			if (!split[i])
			{
				ft_free_split(split, i);
				return (1);
			}
			i++;
		}
		s = current + 1;
	}
	split[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	split = ft_calloc((count + 1), sizeof(char *));
	if (!split)
		return (NULL);
	if (ft_split_word(split, s, c, count))
		return (NULL);
	return (split);
}
