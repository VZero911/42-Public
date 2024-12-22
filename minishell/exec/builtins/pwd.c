/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:55:58 by marvin            #+#    #+#             */
/*   Updated: 2024/12/19 08:15:12 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_pwd_command(t_state *state)
{
	char	current_path[1024];

	if (ft_strlen(state->current_path) > 0)
		printf("%s\n", state->current_path);
	else
	{
		if (getcwd(current_path, sizeof(current_path)) != NULL)
		{
			printf("%s\n", current_path);
			ft_strlcpy(state->current_path, current_path,
				ft_strlen(current_path) + 1);
		}
		else
		{
			perror("pwd: error getting current working directory");
		}
	}
}
