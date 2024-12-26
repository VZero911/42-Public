/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:23:50 by marvin            #+#    #+#             */
/*   Updated: 2024/12/11 21:23:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Terminator command to work in school killall ibus-daemon

void	print_command_list(t_command *cmd)
{
	int	i;

	while (cmd)
	{
		printf("Command arguments:\n");
		i = -1;
		while (cmd->args && cmd->args[++i])
			printf("  args[%d]: %s\n", i, cmd->args[i]);
		if (cmd->infile)
			printf("Input file: %s\n", cmd->infile);
		if (cmd->outfile)
			printf("Output file: %s\n", cmd->outfile);
		if (cmd->limiter)
			printf("Heredoc limiter: %s\n", cmd->limiter);
		printf("Is append: %d\n", cmd->append);
		printf("Is pipe: %d\n", cmd->is_pipe);
		printf("----------\n");
		cmd = cmd->next;
	}
}

int	handle_user_input(char *input, t_state *state)
{
	t_command	*cmd;

	if (ft_strcmp(input, "exit") == 0)
	{
		printf("Goodbye!\n");
		free(input);
		exit(EXIT_SUCCESS);
	}
	add_history(input);
	cmd = init_command();
	if (!cmd)
	{
		printf("Error: Init Commands Struct failed\n");
		return (EXIT_FAILURE);
	}
	cmd = parse_input(&cmd, input, state->envp);
	print_command_list(cmd);
	if (cmd)
		exec_shell(cmd, state);
	else
		printf("Error: Parsing failed: %s\n", input);
	return (0);
}

void	display_prompt(t_state *state)
{
	char	*input;

	while (1)
	{
		input = readline("\001\033[1;32m\002ᴍᴀᴇꜱᴛʀᴏꜱʜᴇʟʟ > \001\033[0m\002");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		reset_state(state);
		if (*input)
			handle_user_input(input, state);
		free(input);
	}
}

int	init_state(t_state *state, char **envp)
{
	state->envp = copy_environment(envp);
	if (!state->envp)
	{
		return (EXIT_FAILURE);
	}
	state->last_exit_status = 0;
	state->num_pipes = 0;
	state->index = 0;
	if (getcwd(state->current_path, sizeof(state->current_path)) == NULL)
	{
		perror("Initialization: getcwd error");
		ft_strlcpy(state->current_path, "", 1);
		free_environment(state->envp);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	t_state	shell_state;

	(void) argc, (void) argv;
	if (init_state(&shell_state, envp) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	setup_signals();
	printf("Welcome to Minishell! Type 'exit' to quit.\n");
	display_prompt(&shell_state);
	rl_clear_history();
	free_environment(shell_state.envp);
	return (EXIT_SUCCESS);
}
