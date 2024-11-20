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

void	free_data(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->z_matrix[i++]);
	free(data->z_matrix);
	free(data);
}