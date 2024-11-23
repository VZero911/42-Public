/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:02:08 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/23 05:02:19 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_mouse(int button, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
	{
		if (button == MOUSE_WHEEL_UP)
			data->zoom *= ZOOM_FACTOR;
		else
		{
			data->zoom /= ZOOM_FACTOR;
			if (data->zoom < 0.2)
				data->zoom = 0.2;
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
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image,
			data->shift_x, data->shift_y);
	}
	return (0);
}

int	process_keypress(int keysym, t_fdf *data)
{
	if (keysym == KEY_UP)
		data->shift_y -= MOVE_SPEED;
	else if (keysym == KEY_DOWN)
		data->shift_y += MOVE_SPEED;
	else if (keysym == KEY_LEFT)
		data->shift_x -= MOVE_SPEED;
	else if (keysym == KEY_RIGHT)
		data->shift_x += MOVE_SPEED;
	else if (keysym == KEY_Q)
		data->rotation_z += ROTATE_ANGLE;
	else if (keysym == KEY_E)
		data->rotation_z -= ROTATE_ANGLE;
	else if (keysym == KEY_W)
		data->rotation_x += ROTATE_ANGLE;
	else if (keysym == KEY_S)
		data->rotation_x -= ROTATE_ANGLE;
	else if (keysym == KEY_A)
		data->rotation_y += ROTATE_ANGLE;
	else if (keysym == KEY_D)
		data->rotation_y -= ROTATE_ANGLE;
	else if (keysym == KEY_P)
		data->projection = (data->projection + 1) % 5;
	else if (keysym == XK_Escape)
		handle_close(data);
	return (0);
}

int	handle_keypress(int keysym, t_fdf *data)
{
	process_keypress(keysym, data);
	mlx_destroy_image(data->mlx_ptr, data->image);
	data->image = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->image)
		return (MLX_ERROR);
	data->adress = mlx_get_data_addr(data->image, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->adress)
		return (MLX_ERROR);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	return (0);
}

void	setup_hooks(t_fdf *data)
{
	mlx_mouse_hook(data->win_ptr, handle_mouse, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win_ptr, Event_close, 0, handle_close, data);
}

int	data_init(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_WIDTH, "FdF");
	if (!data->win_ptr)
		return (MLX_ERROR);
	data->image = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->image)
		return (MLX_ERROR);
	data->adress = mlx_get_data_addr(data->image, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->adress)
		return (MLX_ERROR);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	setup_hooks(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
