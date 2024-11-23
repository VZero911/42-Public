/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:13 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/21 02:42:31 by marvin           ###   ########.fr       */
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

int handle_mouse(int button, int x, int y, t_fdf *data)
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

int handle_keypress(int keysym, t_fdf *data)
{
    if (keysym == KEY_W)
        data->shift_y -= MOVE_SPEED;
    else if (keysym == KEY_S)
        data->shift_y += MOVE_SPEED;
    else if (keysym == KEY_A)
        data->shift_x -= MOVE_SPEED;
    else if (keysym == KEY_D)
        data->shift_x += MOVE_SPEED;
    else if (keysym == XK_Escape)
		handle_close(data);
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
    return (0);
}

void setup_hooks(t_fdf *data)
{
	mlx_mouse_hook(data->win_ptr, handle_mouse, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win_ptr, Event_close, 0, handle_close, data);
}

int data_init(t_fdf *data)
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
