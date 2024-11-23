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

void	free_data(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->z_matrix[i++]);
	free(data->z_matrix);
	free(data);
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
        return (0xFF00FF);
    if (max_z > 5)
        return (0xFF00FF);
    return (0x00FF00);
}

