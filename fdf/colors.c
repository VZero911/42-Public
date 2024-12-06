/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:59:06 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/06 21:47:39 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calculate_negative_color(int z)
{
	if (z <= -50)
		return (0x000033);
	if (z <= -45)
		return (0x000080);
	if (z <= -40)
		return (0x0000FF);
	if (z <= -35)
		return (0x1E90FF);
	if (z <= -30)
		return (0x4682B4);
	if (z <= -25)
		return (0x6495ED);
	if (z <= -20)
		return (0x87CEFA);
	if (z <= -15)
		return (0xADD8E6);
	if (z <= -10)
		return (0xB0E0E6);
	if (z <= -8)
		return (0x00CED1);
	if (z <= -6)
		return (0x20B2AA);
	if (z <= -4)
		return (0x00FF7F);
	return (-1);
}

int	calculate_interval_color(int z)
{
	if (z <= -2)
		return (0xFAEBD7);
	if (z <= 0)
		return (0xF5DEB3);
	if (z <= 2)
		return (0xEEE8AA);
	if (z <= 4)
		return (0xD2B48C);
	if (z <= 6)
		return (0xCD853F);
	if (z <= 8)
		return (0xBC8F8F);
	if (z <= 10)
		return (0xA0522D);
	if (z <= 15)
		return (0x8B4513);
	if (z <= 20)
		return (0x6B8E23);
	if (z <= 25)
		return (0x556B2F);
	if (z <= 30)
		return (0x228B22);
	if (z <= 35)
		return (0x32CD32);
	return (-1);
}

int	calculate_high_color(int z)
{
	if (z <= 40)
		return (0x808080);
	if (z <= 45)
		return (0xA9A9A9);
	if (z <= 50)
		return (0xD3D3D3);
	if (z <= 60)
		return (0xFFFFFF);
	if (z <= 70)
		return (0xF0F8FF);
	if (z <= 80)
		return (0xE6E6FA);
	if (z <= 90)
		return (0xFFD700);
	if (z <= 100)
		return (0xDAA520);
	if (z <= 110)
		return (0x8B0000);
	if (z <= 120)
		return (0x800080);
	return (0x4B0082);
}

int	calculate_color(int z1, int z2)
{
	int	max_z;
	int	color;

	max_z = z1;
	if (z2 > max_z)
		max_z = z2;
	color = calculate_negative_color(max_z);
	if (color != -1)
		return (color);
	color = calculate_interval_color(max_z);
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
		data->coef = 3;
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
