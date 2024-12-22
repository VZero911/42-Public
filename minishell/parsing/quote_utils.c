/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 01:04:04 by vboxuser          #+#    #+#             */
/*   Updated: 2024/12/19 02:19:42 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	handle_token(t_token **head, const char *input, int *i, char **envp)
{
	int		start;
	char	*temp;

	if (input[*i] == '\'')
		temp = parse_single_quote(input, i);
	else if (input[*i] == '"')
		temp = parse_double_quote(input, i, envp);
	else if (input[*i] == '$')
		temp = expand_variable((char *)input, i, envp);
	else
	{
		start = *i;
		while (input[*i] && !is_special_char(input[*i]))
			(*i)++;
		temp = ft_substr(input, start, *i - start);
	}
	if (!temp)
		return (-1);
	if (!create_and_add_token(head, temp))
	{
		free(temp);
		return (-1);
	}
	free(temp);
	return (0);
}

int	is_special_char(char c)
{
	return (c == ' ' || c == '\t' || c == '\'' || c == '"' || c == '$');
}

char	*parse_single_quote(const char *input, int *i)
{
	int	start;

	(*i)++;
	start = *i;
	while (input[*i] && input[*i] != '\'')
		(*i)++;
	return (ft_substr(input, start, *i - start));
}

char	*parse_double_quote(const char *input, int *i, char **envp)
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
			temp = expand_variable((char *)input, i, envp);
			result = ft_strjoin_free(result, temp);
		}
	}
	if (input[*i] == '"')
		(*i)++;
	return (result);
}
