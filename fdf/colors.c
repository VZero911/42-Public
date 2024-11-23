/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:59:06 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/23 08:01:08 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calculate_low_color(int z)
{
	if (z <= -40)
		return (0x191970);
	if (z <= -30)
		return (0x000080);
	if (z <= -20)
		return (0x00008B);
	if (z <= -10)
		return (0x1E90FF);
	if (z <= 0)
		return (0x00BFFF);
	if (z <= 10)
		return (0x7CFC00);
	if (z <= 20)
		return (0x32CD32);
	if (z <= 30)
		return (0x228B22);
	if (z <= 40)
		return (0x6B8E23);
	return (-1);
}

int	calculate_high_color(int z)
{
	if (z <= 50)
		return (0x8B4513);
	if (z <= 60)
		return (0xA0522D);
	if (z <= 70)
		return (0xD2691E);
	if (z <= 80)
		return (0xFFFFFF);
	return (0xFFD700);
}

int	calculate_color(int z1, int z2)
{
	int	max_z;
	int	color;

	max_z = z1;
	if (z2 > max_z)
		max_z = z2;
	color = calculate_low_color(max_z);
	if (color != -1)
		return (color);
	return (calculate_high_color(max_z));
}

int	process_space(int keysym, t_fdf *data)
{
	if (keysym == KEY_SPACE)
	{
		data->zoom = 5.0;
		data->shift_x = 0;
		data->shift_y = 0;
		data->rotation_x = 0.0;
		data->rotation_y = 0.0;
		data->rotation_z = 0.0;
		data->projection = ISO;
	}
	mlx_destroy_image(data->mlx_ptr, data->image);
	data->image = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->image)
		return (MLX_ERROR);
	data->adress = mlx_get_data_addr(data->image, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->adress)
		return (MLX_ERROR);
	draw_map(data);
	return (0);
}
