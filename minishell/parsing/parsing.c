/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 03:01:45 by vboxuser          #+#    #+#             */
/*   Updated: 2024/12/22 02:39:54 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*handle_special_var(char c)
{
	char	*value;

	if (c == '?')
	{
		value = getenv("EXIT_STATUS");
		if (!value)
			return (ft_strdup("0"));
		return (ft_strdup(value));
	}
	return (NULL);
}

// Fonction pour gérer les variables dans les doubles quotes
char	*expand_variable(char *input, int *i, char **envp)
{
	char	*key;
	char	*value;
	int	start;

	(void)envp;
	(*i)++;
	value = handle_special_var(input[*i]);// ajoute le EXIT_STATUS dans le env -> pas comme bash
	if (value)
	{
		(*i)++;
		return (value);
	}
	start = *i;
	while (input[*i] && (ft_isalnum(input[*i]) || input[*i] == '_'))
		(*i)++;
	key = ft_substr(input, start, *i - start);
	if (!key)
		return (NULL);
	value = getenv(key);
	free(key);
	if (value)
		return (ft_strdup(value));
	return (ft_strdup(""));
}


int	convert_tokens_to_command(t_command *cmd, t_token *tokens)
{
	int			arg_index;
	t_token		*current;
	t_command	*current_cmd;
	arg_index = 0;
	current = tokens;
	current_cmd = cmd;
	current_cmd->args[0] = NULL;
	while (current)
	{
		if (!ft_strcmp(current->content, "<")
			||!ft_strcmp(current->content, ">")
			|| !ft_strcmp(current->content, ">>")
			|| !ft_strcmp(current->content, "<<"))
		{
			if (handle_redirection(current_cmd, current) == -1)
				return (-1);
			current = current->next;
		}
		else if (!ft_strcmp(current->content, "|"))
		{
			current_cmd->is_pipe = 1;
			current_cmd->args[arg_index] = NULL; 
            current_cmd->next = add_new_node();
            if (!current_cmd->next)
                return (free_command_list(cmd), -1);
			if (current->next && !current->next->prev)
				current->next->prev = current;
			if (current->next)
            	current_cmd = current_cmd->next;
            arg_index = 0;
			current_cmd->args[0] = NULL; 
		}
		else
		{
			if (handle_arguments(current_cmd, current, &arg_index) == -1)
				return (-1);
		}
		current = current->next;
	}
	current_cmd->args[arg_index] = NULL;
	return (0);
}

// int	convert_tokens_to_command(t_command *cmd, t_token *tokens)
// {
// 	int		arg_index;
// 	t_token	*current;
// 	t_command *current_cmd;

// 	arg_index = 0;
// 	current = tokens;
// 	current_cmd = cmd;
// 	current_cmd->args[0] = NULL;
// 	while (current)
// 	{
// 		if (!ft_strcmp(current->content, "<"))
// 		{
// 			if (!current->prev || !ft_strcmp(current->prev->content, "|"))
// 			{
// 				if (current->next && current->next->content)
// 				{
// 					current_cmd->infile = ft_strdup(current->next->content);	
// 					current = current->next;				
// 				}
				
// 			}
// 			else
// 			{
// 				if (current->next && current->next->content)
// 				{
// 					current_cmd->infile = ft_strdup(current->next->content);
// 					current = current->next;				
// 				}
// 			}
// 		}
// 		else if (!ft_strcmp(current->content, ">") && current->next)
// 		{
// 			current_cmd->outfile = ft_strdup(current->next->content);
// 			current = current->next;
// 		}
// 		else if (!ft_strcmp(current->content, "<<") && current->next)
// 		{
// 			current_cmd->limiter = ft_strdup(current->next->content);
// 			current = current->next;
// 			current_cmd->heredoc = 1;
// 		}
// 		else if (!ft_strcmp(current->content, ">>") && current->next)
// 		{
// 			current_cmd->outfile = ft_strdup(current->next->content);
// 			current = current->next;
// 			current_cmd->append = 1;
// 		}
// 		else if (!ft_strcmp(current->content, "|"))
// 		{
// 			current_cmd->is_pipe = 1;
// 			current_cmd->args[arg_index] = NULL; 
//             current_cmd->next = add_new_node();
//             if (!current_cmd->next)
//                 return (-1);
//             current_cmd = current_cmd->next;
//             arg_index = 0;
// 			current_cmd->args[0] = NULL; 
// 		}
// 		else
// 		{
// 			if (handle_arguments(current_cmd, current, &arg_index) == -1)
// 				return (-1);
// 		}
// 		current = current->next;
// 	}
// 	cmd->args[arg_index] = NULL;
// 	return (0);
// }


// Fonction principale pour parser l'input utilisateur
t_command	*parse_input(t_command **cmd, const char *input, char **envp)
{
	t_token		*tokens;

	tokens = tokenize_input(input, envp);
	if (!tokens)
		return (NULL);
	if (convert_tokens_to_command((*cmd), tokens) == -1)
	{
		free_tokens(tokens);
		free_command_list((*cmd));
		return (NULL);
	}
	free_tokens(tokens);
	return ((*cmd));
}
