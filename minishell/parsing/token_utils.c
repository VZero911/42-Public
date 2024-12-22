/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 06:20:12 by vboxuser          #+#    #+#             */
/*   Updated: 2024/12/19 15:44:05 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Fonction pour ajouter un token dans la liste chaînée
t_token	*create_and_add_token(t_token **head, char *content)
{
	t_token	*new_token;
	t_token	*tmp;

	if (!content)
		return (NULL);
	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->content = ft_strdup(content);
	if (!new_token->content)
		return (free(new_token), NULL);
	new_token->next = NULL;
	new_token->prev = NULL;
	if (!*head)
		*head = new_token;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token;
		new_token->prev = tmp;
	}
	return (new_token);
}

// Tokenization de l'input utilisateur
t_token	*tokenize_input(const char *input, char **envp)
{
	int		i;
	t_token	*token_list;

	token_list = NULL;
	i = 0;
	if (check_unclosed_quotes(input))
	{
		printf("minishell: syntax error: quotes not closed\n");
		return (NULL);
	}
	while (input[i])
	{
		i = skip_spaces(input, i);
		if (!input[i])
			break ;
		if (handle_token(&token_list, input, &i, envp) == -1)
		{
			free_tokens(token_list);
			return (NULL);
		}
	}
	return (token_list);
}

// Fonction pour libérer la mémoire des tokens
void	free_tokens(t_token *head)
{
	t_token	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		if (tmp->content)
		{
			free(tmp->content);
			tmp->content = NULL;
		}
		free(tmp);
	}
}
