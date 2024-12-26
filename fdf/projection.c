/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:02:08 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/26 20:56:18 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project_top(double x, double y, double z, t_fdf *data)
{
	t_point	p;

	p.x = x * data->zoom + WIN_WIDTH / 2;
	p.y = y * data->zoom + WIN_HEIGHT / 2;
	p.z = z;
	return (p);
}

t_point	project_military(double x, double y, double z, t_fdf *data)
{
	t_point	p;

	p.x = x * data->zoom + WIN_WIDTH / 2;
	p.y = (y - z * data->coef) * data->zoom + WIN_HEIGHT / 2;
	p.z = z;
	return (p);
}

t_point	project_cabinet(double x, double y, double z, t_fdf *data)
{
	t_point	p;
	double	factor;

	factor = 0.5;
	p.x = (x - z * factor * cos(0.785398)) * data->zoom + WIN_WIDTH / 2;
	p.y = (y - z * factor * sin(0.785398)) * data->zoom + WIN_HEIGHT / 2;
	p.z = z;
	return (p);
}

t_point	project_parallel(double x, double y, double z, t_fdf *data)
{
	t_point	p;

	p.x = (x * data->zoom + WIN_WIDTH / 3);
	p.y = (y * data->zoom + WIN_HEIGHT / 3) - (z * data->coef);
	p.z = z;
	return (p);
}

t_point	project_isometric(double x, double y, double z, t_fdf *data)
{
	t_point	p;

	p.x = (x - y) * cos(ISO_ANGLES) * data->zoom + WIN_WIDTH / 2;
	p.y = ((x + y) * sin(ISO_ANGLES) - ((z * data->coef) / 8))
		* data->zoom + WIN_HEIGHT / 2;
	p.z = (z * data->coef) / 8;
	return (p);
}
