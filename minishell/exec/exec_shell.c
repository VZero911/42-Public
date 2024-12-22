/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:40:35 by vboxuser          #+#    #+#             */
/*   Updated: 2024/12/19 05:40:35 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_builtins(t_command *cmd, t_state *state)
{
	if (ft_strcmp(cmd->args[0], "cd") == 0)
		return (handle_cd_command(cmd->args, state), 1);
	else if (ft_strcmp(cmd->args[0], "pwd") == 0)
		return (handle_pwd_command(state), 1);
	else if (ft_strcmp(cmd->args[0], "env") == 0)
		return (handle_env_command(state->envp), 1);
	else if (ft_strcmp(cmd->args[0], "echo") == 0)
    	return (handle_echo_command(cmd), 1);
	else if (ft_strcmp(cmd->args[0], "unset") == 0)
		return (handle_unset_command(cmd->args, state->envp), 1);
	else if (ft_strcmp(cmd->args[0], "export") == 0)
		return (handle_export_command(cmd->args, state), 1);
	else if (ft_strcmp(cmd->args[0], "neosnitch") == 0)
		return (handle_neosnitch_command(cmd->args, state), 1);
	return (0);
}

void	reset_state(t_state *state)
{
	state->num_pipes = 0;
	state->index = 0;
}

void	exec_shell(t_command *cmd, t_state *state)
{
	// if (cmd && cmd->heredoc && !cmd->args)
	// 	return (cat_heredoc(cmd));
	if (!cmd->args || !cmd->args[0])
		return (free_command_list(cmd));
	if (exec_builtins(cmd, state) && !cmd->is_pipe)
		return (free_command_list(cmd));
	if (!cmd->is_pipe)
		handle_external_cmd(cmd, cmd->args, state);
	if (cmd->is_pipe)
		handle_multiples_pipes(cmd, state);
	free_command_list(cmd);
}
