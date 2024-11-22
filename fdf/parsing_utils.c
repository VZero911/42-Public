/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:13 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/21 22:10:29 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_width(t_fdf *data, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	data->width = count_split_elements(split);
	free_split(split);
	free(line);
}

int	count_split_elements(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

void	process_line_width(t_fdf *data, char *line)
{
	char	**split;
	int		line_width;

	split = ft_split(line, ' ');
	line_width = count_split_elements(split);
	free_split(split);
	if (line_width != data->width)
	{
		free(line);
		error("Inconsistent line width in map");
	}
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