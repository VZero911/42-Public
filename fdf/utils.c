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

int	handle_close(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_data(data);
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

int	calculate_color(int z1, int z2)
{
	int	max_z;

	max_z = z1;
	if (z2 > max_z)
		max_z = z2;
	if (max_z <= 5)
		return (0x00008B);
	if (max_z <= 10)
		return (0x1E90FF);
	if (max_z <= 15)
		return (0x00BFFF);
	if (max_z <= 20)
		return (0x7CFC00);
	if (max_z <= 30)
		return (0x32CD32);
	if (max_z <= 40)
		return (0x228B22);
	if (max_z <= 50)
		return (0x6B8E23);
	if (max_z <= 60)
		return (0x8B4513);
	if (max_z <= 70)
		return (0xA0522D);
	return (0xFFFFFF);
}
