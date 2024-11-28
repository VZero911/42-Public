/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:02:08 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/28 17:09:40 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	if ((y * data->line_length + x * (data->bits_per_pixel / 8)) >= \
		(WIN_HEIGHT * data->line_length))
		return ;
	dst = data->adress + (y * data->line_length + \
		x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	rotate_point(double *x, double *y, double *z, t_fdf *data)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(data->rotation_x) - prev_z * sin(data->rotation_x);
	*z = prev_y * sin(data->rotation_x) + prev_z * cos(data->rotation_x);
	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(data->rotation_y) + prev_z * sin(data->rotation_y);
	*z = -prev_x * sin(data->rotation_y) + prev_z * cos(data->rotation_y);
	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(data->rotation_z) - prev_y * sin(data->rotation_z);
	*y = prev_x * sin(data->rotation_z) + prev_y * cos(data->rotation_z);
}

t_point	project_point(t_fdf *data, int x, int y, int z)
{
	double	proj_x;
	double	proj_y;
	double	proj_z;

	proj_x = x - (data->width - 1) / 2.0;
	proj_y = y - (data->height - 1) / 2.0;
	proj_z = z;
	rotate_point(&proj_x, &proj_y, &proj_z, data);
	proj_x += data->shift_x;
	proj_y += data->shift_y;
	if (data->projection == ISO)
		return (project_isometric(proj_x, proj_y, proj_z, data));
	else if (data->projection == PARALLEL)
		return (project_parallel(proj_x, proj_y, proj_z, data));
	else if (data->projection == TOP)
		return (project_top(proj_x, proj_y, proj_z, data));
	else if (data->projection == MILITARY)
		return (project_military(proj_x, proj_y, proj_z, data));
	return (project_cabinet(proj_x, proj_y, proj_z, data));
}

void	draw_line(t_fdf *data, t_point start, t_point end)
{
	t_point	cur;
	int		steps;
	int		i;

	cur = start;
	cur.delta_x = end.x - start.x;
	cur.delta_y = end.y - start.y;
	steps = fmax(fabs(cur.delta_x), fabs(cur.delta_y)) + 1;
	cur.x_increment = cur.delta_x / (double)steps;
	cur.y_increment = cur.delta_y / (double)steps;
	cur.color = calculate_color(start.z, end.z);
	i = -1;
	while (++i <= steps)
	{
		my_mlx_pixel_put(data, round(cur.x), round(cur.y), cur.color);
		cur.x += cur.x_increment;
		cur.y += cur.y_increment;
	}
}

void	draw_map(t_fdf *data)
{
	t_point	end;

	data->y = -1;
	while (++data->y < data->height)
	{
		data->x = -1;
		while (++data->x < data->width)
		{
			data->current = project_point(data, data->x, data->y, \
				data->z_matrix[data->y][data->x]);
			if (data->x < data->width - 1)
			{
				end = project_point(data, data->x + 1, data->y, \
					data->z_matrix[data->y][data->x + 1]);
				draw_line(data, data->current, end);
			}
			if (data->y < data->height - 1)
			{
				end = project_point(data, data->x, data->y + 1, \
					data->z_matrix[data->y + 1][data->x]);
				draw_line(data, data->current, end);
			}
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
}
