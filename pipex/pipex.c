/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:09:29 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/25 01:38:38 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char **env)
{
	int fd[2];
	int i = pipe(fd);
	int id = fork();
	int j = 0;
	if (id == 0)
	{
		int z = execve("ping", &argv[1], env);
		int x = 10;
		close(fd[0]);
		printf("Je suis l'enfant\n");
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		wait(NULL);
		int y;
		printf("Je suis le parent\n");
		close(fd[1]);
		read(fd[0], &y, sizeof(int));
		printf("%d\n", y);
		close(fd[0]);
		
	}
	return 0;
}
