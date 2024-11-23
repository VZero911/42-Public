/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:13 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/23 06:12:46 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc == 2 || argc == 4)
	{
		check_file_name(argv[1]);
		data = (t_fdf *)malloc(sizeof(t_fdf));
		if (!data)
			error("Malloc error");
		data->file_name = argv[1];
		data->zoom = 5.0;
		data->y = 0;
		data->x = 0;
		data->shift_x = 0;
		data->shift_y = 0;
		data->rotation_x = 0.0;
		data->rotation_y = 0.0;
		data->rotation_z = 0.0;
		data->projection = ISO;
		read_file(data);
		data_init(data);
		free_data(data);
	}
	else
		error("Wrong number of Arguments");
}
