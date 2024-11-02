/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 17:08:41 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	fd1 = open("file1.txt", O_RDONLY);
	if (fd1 < 0)
	{
		printf("Error opening file1.txt\n");
		return (1);
	}
	fd2 = open("file2.txt", O_RDONLY);
	if (fd2 < 0)
	{
		printf("Error opening file2.txt\n");
		close(fd1);
		return (1);
	}
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	while (line1 != NULL || line2 != NULL)
	{
		if (line1)
		{
			printf("%s", line1); 
			free(line1);
			line1 = get_next_line(fd1);
		}
		if (line2)
		{
			printf("%s", line2);
			free(line2);
			line2 = get_next_line(fd2);
		}
	}
	close(fd1);
	close(fd2);
	return (0);
}
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c -o gnl_test
