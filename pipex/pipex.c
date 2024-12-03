/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:09:29 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/03 18:29:45 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex, int argc, char **argv)
{
	pipex->output_file = argv[argc - 1];
	pipex->input_file = argv[1];
	pipex->pipe_count = argc - 4;
	pipex->input_fd = -1;
	pipex->output_fd = -1;
	pipex->pipes = NULL;
	pipex->pid = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2);
		ft_putstr_fd("Or\nUsage: ./pipex infile \"cmd1\" \"cmd2\" \"cmd3\" ", 2);
		ft_putstr_fd("... \"cmdn\" outfile\nOr\nUsage : ./pipex heredoc", 2);
		ft_putstr_fd(" EOF \"cmd1\" \"cmd2\" outfile\nOr\n", 2);
		return (ft_putstr_fd("Usage : ./pipex EOF \"cmd1\" outfile\n", 2), 0);
	}
	init_pipex(&pipex, argc, argv);
	if (!ft_strncmp(pipex.input_file, "here_doc", 8))
	{
		if (!(argc == 5 || argc == 6))
		{
			ft_putstr_fd("Usage : ./pipex heredoc", 2);
			return (ft_putstr_fd(" EOF \"cmd1\" \"cmd2\" outfile\n", 2), 0);
		}
		pipex.pipe_count = 1;
		handle_heredoc(&pipex, argc, argv, envp);
	}
	else
		multiples_pipes(&pipex, argv, envp);
	return (0);
}
