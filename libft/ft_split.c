/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 14:44:29 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_split(char **split, size_t i)
{
	while (i > 0)
	{
		i--;
		free(split[i]);
	}
	free(split);
}

static size_t	ft_word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	ft_split_words(char **split, const char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			len = ft_word_len(s, c);
			split[i] = ft_substr(s, 0, len);
			if (!split[i])
			{
				ft_free_split(split, i);
				return (1);
			}
			i++;
			s += len;
		}
	}
	split[i] = NULL;
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	split = ft_calloc(count + 1, sizeof(char *));
	if (!split)
		return (NULL);
	if (ft_split_words(split, s, c))
		return (NULL);
	return (split);
}
/*int	main(void)
{
	char	str[] = "Hello   world this  is   a   test";
	char	delimiter = ' ';
	char	**result;
	size_t	i;

	result = ft_split(str, delimiter);
	if (!result)
	{
		return (1);
	}
	i = 0;
	while (result[i])
	{
		printf("Mot %zu: %s\n", i + 1, result[i]);
		i++;
	}
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);

	return (0);
}*/
