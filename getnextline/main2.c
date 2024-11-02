/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 17:44:17 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	char	*line1;

	fd1 = open("file2.txt", O_RDONLY);
	if (fd1 < 0)
	{
		printf("Error opening file2.txt\n");
		return (1);
	}
	line1 = get_next_line(fd1);
	printf("%s", line1);
	free(line1);
	/*while (line1 != NULL)
	{
		if (line1)
		{
			printf("%s", line1);
			free(line1);
			line1 = get_next_line(fd1);
		}
	}*/
	close(fd1);
	return (0);
}
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c -o gnl_test
