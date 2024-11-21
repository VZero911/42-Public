/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:13 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/21 06:55:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char    *dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = data->adress + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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

void    draw_line_loop(t_fdf *data, t_point current, t_point end)
{
	int i = 0;
	while (i <= current.steps)
	{
		my_mlx_pixel_put(data, round(current.x), round(current.y), current.color);
		current.x += current.x_increment;
		current.y += current.y_increment;
		i++;
	}
}

void    draw_line(t_fdf *data, t_point start, t_point end)
{
	start.delta_x = end.x - start.x;
	start.delta_y = end.y - start.y;
	start.color = calculate_color(start.z, end.z);
	start.steps = abs((int)start.delta_x);
	if (abs((int)start.delta_y) > start.steps)
		start.steps = abs((int)start.delta_y);
	
	start.x_increment = start.delta_x / (float)start.steps;
	start.y_increment = start.delta_y / (float)start.steps;
	draw_line_loop(data, start, end);
}

t_point project_point(t_fdf *data, int x, int y, int z)
{
	t_point projected;
	
	projected.x = (x - y) * cos(ISO_ANGLES) + WIN_WIDTH / 2;
	projected.y = (x + y) * sin(ISO_ANGLES) - z * 0.5 + WIN_HEIGHT / 2;
	projected.z = z;
	projected.x *= data->zoom;
	projected.y *= data->zoom;
	return (projected);
}

void    draw_map(t_fdf *data)
{
	if (data->zoom == 0)
	{
		if (WIN_WIDTH / (2 * data->width) < WIN_HEIGHT / (2 * data->height))
			data->zoom = WIN_WIDTH / (2 * data->width);
		else
			data->zoom = WIN_HEIGHT / (2 * data->height);
	}
	while (data->y < data->height)
	{
		while (data->x < data->width)
		{
			data->current = project_point(data, data->x, data->y, data->z_matrix[data->y][data->x]);
			if (data->x < data->width - 1)
			{
				data->right = project_point(data, data->x + 1, data->y, data->z_matrix[data->y][data->x + 1]);
				draw_line(data, data->current, data->right);
			}
			if (data->y < data->height - 1)
			{
				data->down = project_point(data, data->x, data->y + 1, data->z_matrix[data->y + 1][data->x]);
				draw_line(data, data->current, data->down);
			}
			data->x++;
		}
		data->y++;
	}
}
