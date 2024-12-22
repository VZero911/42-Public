/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 01:12:08 by vboxuser          #+#    #+#             */
/*   Updated: 2024/12/19 02:19:38 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_unclosed_quotes(const char *input)
{
	char	quote;
	int		i;

	quote = '\0';
	i = 0;
	while (input[i])
	{
		if ((input[i] == '\'' || input[i] == '"') && !quote)
			quote = input[i];
		else if (input[i] == quote)
			quote = '\0';
		i++;
	}
	if (quote)
		return (1);
	return (0);
}

// Fonction pour gérer les doubles quotes
char	*handle_double_quotes(const char *input, int *i, char **envp)
{
	int		start;
	char	*result;
	char	*temp;

	(*i)++;
	result = ft_strdup("");
	while (input[*i] && input[*i] != '"')
	{
		start = *i;
		while (input[*i] && input[*i] != '"' && input[*i] != '$')
			(*i)++;
		temp = ft_substr(input, start, *i - start);
		result = ft_strjoin_free(result, temp);
		if (input[*i] == '$')
		{
			(*i)++;
			temp = expand_variable((char *)input, i, envp);
			result = ft_strjoin_free(result, temp);
		}
	}
	if (input[*i] == '"')
		(*i)++;
	return (result);
}

// Fonction pour gérer les quotes simples
char	*handle_single_quotes(const char *input, int *i)
{
	int		start;
	char	*result;

	start = ++(*i);
	while (input[*i] && input[*i] != '\'')
		(*i)++;
	result = ft_substr(input, start, *i - start);
	if (input[*i] == '\'')
		(*i)++;
	return (result);
}

// Fonction pour gérer les tokens avec quotes
char	*parse_quoted_token(const char *input, int *i, char **envp)
{
	if (input[*i] == '\'')
		return (handle_single_quotes(input, i));
	else if (input[*i] == '"')
		return (handle_double_quotes(input, i, envp));
	return (NULL);
}
