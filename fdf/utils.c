/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:13 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/19 05:34:34 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error(char *str)
{
	ft_printf("%s\n", str);
	exit (1);
}

int	check_file_name(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (i < 4)
		error("Wrong Format should be <.fdf>");
	if (file_name[i - 1] != 'f' || file_name[i - 2] != 'd' || i < 4
		|| file_name[i - 3] != 'f' || file_name[i - 4] != '.')
		error("Wrong Format should be <.fdf>");
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_matrix(int **matrix, int height)
{
	int	i;

	i = height;
	while (i >= 0)
		free(matrix[i--]);
	free(matrix);
}

int     calculate_color(int z1, int z2)
{
    int max_z;

    max_z = z1;
    if (z2 > max_z)
        max_z = z2;
    if (max_z > 10)
        return (0xFF0000);
    if (max_z > 5)
        return (0x00FF00);
    return (0x0000FF);
}
