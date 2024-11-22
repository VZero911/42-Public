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


int	handle_imput(int keysym, t_fdf *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key has been pressed\n\n");
		mlx_destroy_image(data->mlx_ptr, data->image);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed\n\n");
	return (0);
}

int data_init(t_fdf *data)
{
	data->mlx_ptr = mlx_init(); //free i guess
	if (!data->mlx_ptr)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_WIDTH, "FdF"); // free
	if (!data->win_ptr)
		return (MLX_ERROR);
	data->image = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT); // free
	if (!data->image)
		return (MLX_ERROR);
	data->adress = mlx_get_data_addr(data->image, &data->bits_per_pixel, // no free
			&data->line_length, &data->endian);
	if (!data->adress)
		return (MLX_ERROR);
	data->zoom = 0;
	data->y = 0;
	data->x = 0;
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	mlx_key_hook(data->win_ptr, handle_imput, data); // lot of free to do
	mlx_loop(data->mlx_ptr);
	return (0);
}
