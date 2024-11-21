/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:13 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/21 04:46:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	print_data(t_fdf *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < data->height)
// 	{
// 		j = 0;
// 		while (j < data->width)
// 		{
// 			ft_printf("%d ", data->z_matrix[i][j]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// }

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc == 2)
	{
		check_file_name(argv[1]);
		data = (t_fdf *)malloc(sizeof(t_fdf));
		if (!data)
			error("Malloc error");
		data->file_name = argv[1];
		read_file(data);
		free_data(data);
	}
	else
		error("Wrong number of Arguments");
}
