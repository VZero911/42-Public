/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:13 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/19 05:34:34 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error(char *str)
{
	ft_printf("%s\n", str);
	exit (1);
}

int	check_file_name(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (file_name[i - 1] != 'f' || file_name[i - 2] != 'd' || i < 4
		|| file_name[i - 3] != 'f' || file_name[i - 4] != '.')
		error("Wrong Format should be <.fdf>");
	return (0);
}

void	free_data(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->z_matrix[i++]);
	free(data->z_matrix);
	free(data);
}
