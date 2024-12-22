/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neosnitch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:00:55 by vboxuser          #+#    #+#             */
/*   Updated: 2024/12/19 08:21:29 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// oui x)
void	handle_neosnitch_command(char **argv, t_state *state)
{
	(void)argv, (void)state;
	ft_putstr_fd("            .-/+oossssoo+/-.\n", 1);
	ft_putstr_fd("        `:+ssssssssssssssssss+:`\n", 1);
	ft_putstr_fd("      -+ssssssssssssssssssyyssss+-\n", 1);
	ft_putstr_fd("    .ossssssssssssssssssdMMMNysssso.\n", 1);
	ft_putstr_fd("   /ssssssssssshdmmNNmmyNMMMMhssssss/\n", 1);
	ft_putstr_fd("  +ssssssssshmydMMMMMMMNddddyssssssss+\n", 1);
	ft_putstr_fd(" /sssssssshNMMMyhhyyyyhmNMMMNhssssssss/\n", 1);
	ft_putstr_fd(".ssssssssdMMMNhsssssssssyNMMMdssssssss.\n", 1);
	ft_putstr_fd("+sssshhhyNMMNysssso+/-+shhdNMMNysssssss+\n", 1);
	ft_putstr_fd("ossyNMMMNyMMhsssssssssssssshNMMMyssssssso\n", 1);
	ft_putstr_fd("ossyNMMMNyMMhsssssssssssssshNMMMyssssssso\n", 1);
	ft_putstr_fd(" +sssssssdNMMdssssssssssssyNMMMdssssssss+\n", 1);
	ft_putstr_fd("  /sssssssshNMMMyhhyyyyhdNMMMNhssssssss/\n", 1);
	ft_putstr_fd("   +sssssssssdmydMMMMMMMMddddyssssssss+\n", 1);
	ft_putstr_fd("    /ssssssssssshdmNNNNmyNMMMMhssssss/\n", 1);
	ft_putstr_fd("     .ossssssssssssssssssdMMMNysssso.\n", 1);
	ft_putstr_fd("       -+sssssssssssssssssyyyssss+-\n", 1);
	ft_putstr_fd("         `:+ssssssssssssssssss+:`\n", 1);
	ft_putstr_fd("             .-/+oossssoo+/-.\n\n", 1);
	ft_putstr_fd("MaestroShell, version 1.0 By David and Judicaël\n", 1);
	return ;
}
