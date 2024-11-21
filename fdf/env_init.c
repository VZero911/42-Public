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

int	data_init(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free_data(data), free(data->mlx_ptr), MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_WIDTH, "FdF");
	if (!data->win_ptr)
		return (free_data(data), free(data->win_ptr),
			free(data->mlx_ptr), MLX_ERROR);
	mlx_loop(data->mlx_ptr);
}
