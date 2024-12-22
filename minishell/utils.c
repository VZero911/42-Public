/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:25:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 22:25:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_command(t_command *cmd)
{
	int	i;

	if (!cmd)
		return ;
	if (cmd->args)
	{
		i = -1;
		while (cmd->args[++i])
		{
			free(cmd->args[i]);
			cmd->args[i] = NULL;
		}
		free(cmd->args);
		cmd->args = NULL;
	}
	if (cmd->infile)
	{
		free(cmd->infile);
		cmd->infile = NULL;
	}
	if (cmd->outfile)
	{
		free(cmd->outfile);
		cmd->outfile = NULL;
	}
	if (cmd->limiter)
	{
		free(cmd->limiter);
		cmd->limiter = NULL;
	}
	free(cmd);
	cmd = NULL;
}

void	free_environment(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

int	skip_spaces(const char *input, int i)
{
	while (input[i] && (input[i] == ' ' || input[i] == '\t'))
		i++;
	return (i);
}
