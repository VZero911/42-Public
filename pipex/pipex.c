/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:09:29 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/02 11:17:56 by jdumay           ###   ########.fr       */
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
	open_file(&pipex);
	pipex.pipe_count = argc - 4;
	multiples_pipes(&pipex, argv, envp);
	return (0);
}
