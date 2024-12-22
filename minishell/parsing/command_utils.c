/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 06:21:07 by vboxuser          #+#    #+#             */
/*   Updated: 2024/12/22 01:10:07 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Fonction pour initialiser une commande vide
t_command	*init_command(void)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
	{
		perror("Error malloc - t_command struct");
		return (NULL);
	}
	ft_memset(cmd, 0, sizeof(t_command));
	cmd->args = malloc(sizeof(char *) * 256);
	if (!cmd->args)
	{
		perror("Error malloc - args");
		return (free(cmd), NULL);
	}
	ft_memset(cmd->args, 0, sizeof(char *) * 256);
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->limiter = NULL;
	cmd->heredoc = 0;
	cmd->append = 0;
	cmd->is_pipe = 0;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

//fonction pour creer un nouveau noeud
t_command	*add_new_node(void)
{
	t_command	*new_node;

	new_node = init_command();
	if (!new_node)
	{
		perror("Error creating new command node");
		return (NULL);
	}
	return (new_node);
}

// Fonction pour remplir les arguments d'une commande
int	fill_command_args(t_command *cmd, t_token *current, int *index)
{
	char	*arg_copy;

	if (*index >= 255)
		return (-1);
	arg_copy = ft_strdup(current->content);
	if (!arg_copy)
		return (-1);
	cmd->args[*index] = arg_copy;
	(*index)++;
	cmd->args[*index] = NULL;
	return (0);
}

int	handle_pipe(t_command **current_cmd, int *arg_index)
{
	(*current_cmd)->is_pipe = 1;
	(*current_cmd)->args[*arg_index] = NULL;
	(*current_cmd)->next = add_new_node();
	if (!(*current_cmd)->next)
		return (-1);
	*current_cmd = (*current_cmd)->next;
	*arg_index = 0;
	(*current_cmd)->args[0] = NULL;
	return (0);
}

int	handle_arguments(t_command *current_cmd, t_token *current, int *arg_index)
{
	if (fill_command_args(current_cmd, current, arg_index) == -1)
	{
		while (--(*arg_index) >= 0)
		{
			free(current_cmd->args[*arg_index]);
			current_cmd->args[*arg_index] = NULL;
		}
		return (-1);
	}
	return (0);
}
