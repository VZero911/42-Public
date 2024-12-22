/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:23:37 by vboxuser          #+#    #+#             */
/*   Updated: 2024/12/21 04:43:41 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Pour les infiles et outfiles ne pas les ouvrir dans le main processus mais seulemet dans les enfants
// Super importants pour reproduire comment bash fait

int	handle_infile(t_command *cmd, t_token *current)
{
	if (cmd->infile)
		free(cmd->infile);
	if (!current->next || !current->next->content)
	{
		fprintf(stderr, "Error: No file provided for input redirection\n");
		return (-1);
	}
	cmd->infile = ft_strdup(current->next->content);
	if (!cmd->infile)
	{
		perror("Error duplicating infile");
		return (-1);
	}
	return (1);
}

int	handle_outfile(t_command *cmd, t_token *current, int append)
{
	if (cmd->outfile)
		free(cmd->outfile);
	if (!current->next || !current->next->content)
	{
		fprintf(stderr, "Error: No file provided for output redirection\n");
		return (-1);
	}
	cmd->outfile = ft_strdup(current->next->content);
	if (!cmd->outfile)
	{
		perror("Error duplicating outfile");
		return (-1);
	}
	cmd->append = append;
	return (1);
}

int	handle_heredoc_redirection(t_command *cmd, t_token *current)
{
	if (cmd->limiter)
		free(cmd->limiter);
	if (current->next && current->next->content)
		cmd->limiter = ft_strdup(current->next->content);
	else
	{
		fprintf(stderr, "Error: No heredoc limiter provided\n");
		return (-1);
	}
	cmd->heredoc = 1;
	if (handle_heredoc(cmd) == -1)
	{
		free(cmd->limiter);
		cmd->limiter = NULL;
		return (-1);
	}
	return (1);
}

int	handle_redirection(t_command *cmd, t_token *current)
{
	if (!current->next || !current->next->content)
	{
		fprintf(stderr, "minishell: syntax error near unexpected token `newline'\n");
		return (-1);
	}
	if (!ft_strcmp(current->content, "<"))
		return (handle_infile(cmd, current));
	if (!ft_strcmp(current->content, ">"))
		return (handle_outfile(cmd, current, 0));
	if (!ft_strcmp(current->content, ">>"))
		return (handle_outfile(cmd, current, 1));
	if (!ft_strcmp(current->content, "<<"))
		return (handle_heredoc_redirection(cmd, current));
	fprintf(stderr, "Error: Unknown redirection type '%s'\n", current->content);
	return (-1);
}
