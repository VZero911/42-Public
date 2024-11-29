/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:09:29 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/29 01:11:55 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	validate_files(char *input_file, char *output_file)
{
	int	input_fd;
	int	output_fd;

	input_fd = open(input_file, O_RDONLY);
	if (input_fd < 0)
	{
		perror("Error opening input file");
		return (-1);
	}
	close(input_fd);
	output_fd = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output_fd < 0)
	{
		perror("Error opening/creating output file");
		return (-1);
	}
	close(output_fd);
	return (0);
}
