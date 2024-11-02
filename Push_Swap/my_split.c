/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 21:56:18 by salieri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator)
			str++;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			str++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		cursor++;
	while ((str[cursor + len] != separator) && str[cursor + len])
		len++;
	next_str = malloc(sizeof(char) * len + 1);
	if (!next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = 0;
	return (next_str);
}

char	**my_split(char *str, char separator)
{
	int		i;
	int		words_count;
	char	**results;

	i = 0;
	words_count = count_words(str, separator);
	if (!words_count)
		exit(1);
	results = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!results)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			results[i] = malloc(sizeof(char));
			if (results[i] == NULL)
				return (NULL);
			results[i++][0] = 0;
			continue ;
		}
		results[i++] = get_next_word(str, separator);
	}
	results[i] = 0;
	return (results);
}
