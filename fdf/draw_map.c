/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:13 by jdumay            #+#    #+#           */
/*   Updated: 2024/11/21 06:55:09 by marvin           ###   ########.fr     */
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

void    draw_line(t_fdf *data, t_point start, t_point end)
{
	t_point current;
	int     i;
	int     steps;

	current = start;
	current.delta_x = end.x - start.x;
	current.delta_y = end.y - start.y;
	steps = fmax(fabs(current.delta_x), fabs(current.delta_y));
	current.x_increment = current.delta_x / steps;
	current.y_increment = current.delta_y / steps;
	current.color = calculate_color(start.z, end.z);
	i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_put(data, round(current.x), round(current.y), current.color);
		current.x += current.x_increment;
		current.y += current.y_increment;
		i++;
	}
}

t_point project_point(t_fdf *data, int x, int y, int z)
{
	t_point p;
	
	x -= data->width / 2;
	y -= data->height / 2;
	p.x = (x - y) * cos(ISO_ANGLES) * data->zoom + WIN_WIDTH / 2;
	p.y = ((x + y) * sin(ISO_ANGLES) - z) * data->zoom + WIN_HEIGHT / 2;
	p.z = z;
	return (p);
}

void    draw_map(t_fdf *data)
{
	if (!data->zoom)
		data->zoom = fmin(WIN_WIDTH / (2 * data->width), 
						 WIN_HEIGHT / (2 * data->height));
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			data->current = project_point(data, data->x, data->y, 
										data->z_matrix[data->y][data->x]);
			if (data->x < data->width - 1)
				draw_line(data, data->current, project_point(data, 
					data->x + 1, data->y, data->z_matrix[data->y][data->x + 1]));
			if (data->y < data->height - 1)
				draw_line(data, data->current, project_point(data, 
					data->x, data->y + 1, data->z_matrix[data->y + 1][data->x]));
			data->x++;
		}
		data->y++;
	}
}
