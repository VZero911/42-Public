/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 06:21:29 by vboxuser          #+#    #+#             */
/*   Updated: 2024/12/21 23:27:23 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// J'ai changer la facon de gerer les redirections, j'ouvre directement 
// dans le(s) child(ren)
// Meilleur gestion d'erreurs pour les input and output file
/*void	handle_redirections(t_command *cmd)
{
	int	fd;

	if (cmd->infile)
	{
		fd = open(cmd->infile, O_RDONLY);
		if (fd == -1)
		{
			perror("Error opening input file");
			close(fd);
			exit(1);
		}
		dup2(fd, STDIN_FILENO);
		free(cmd->infile);
		close(fd);
	}
	if (cmd->outfile)
	{
		if (cmd->append)
			fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("Error opening output file");
			close(fd);
			exit(1);
		}
		dup2(fd, STDOUT_FILENO);
		free(cmd->outfile);
		close(fd);
	}
}*/

int	handle_redirections(t_command *cmd)
{
	int	fd;

	if (cmd->infile)
	{
		fd = open(cmd->infile, O_RDONLY);
		if (fd == -1)
		{
			perror("Error opening input file");
			return (-1);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	if (cmd->outfile)
	{
		if (cmd->append)
			fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("Error opening output file");
			return (-1);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return (0);
}
