/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:09:29 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/30 03:55:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2);
		ft_putstr_fd("Or\nUsage: ./pipex infile \"cmd1\"", 2);
		ft_putstr_fd(" \"cmd2\" \"cmd3\" ... \"cmdn\" outfile\n", 2);
		return (1);
	}
	pipex.output_file = argv[argc - 1];
	pipex.input_file = argv[1];
	if (validate_files(pipex.input_file, pipex.output_file) < 0)
		return (1);
	if (argc == 5)
		execute_pipex(&pipex, argv, envp);
	else
	{
		pipex.pipe_count = argc - 4;
		open_file(&pipex);
		multiples_pipes(&pipex, argv, envp);
	}
	return (0);
}
