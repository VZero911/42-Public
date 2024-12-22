/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:43:22 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 22:43:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_echo_command(t_command *cmd)
{
	int		i;
	int		newline;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		return (free_command_list(cmd));
	}
	else if (pid == 0)
	{
		if (handle_redirections(cmd) == -1)
		{
			perror("Redirection error");
			free_command_list(cmd);
			exit(1);
		}
		i = 1;
		newline = 1;
		if (cmd->args[1] && ft_strcmp(cmd->args[1], "-n") == 0)
		{
			newline = 0;
			i++;
		}
		while (cmd->args[i])
		{
			ft_putstr_fd(cmd->args[i], STDOUT_FILENO);
			if (cmd->args[i + 1])
				ft_putchar_fd(' ', STDOUT_FILENO);
			i++;
		}
		if (newline)
			ft_putchar_fd('\n', STDOUT_FILENO);
		exit(0);
	}
	waitpid(pid, NULL, 0);
}
