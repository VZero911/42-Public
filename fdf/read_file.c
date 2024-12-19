/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:13 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/21 21:02:06 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**create_matrix(int height, int width)
{
	int	**matrix;
	int	i;

	matrix = (int **)malloc(sizeof(int *) * height);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < height)
	{
		matrix[i] = (int *)malloc(sizeof(int) * width);
		if (!matrix[i])
		{
			free_matrix(matrix, i - 1);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

void	fill_matrix_line(int *z_line, char *line, int width)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	if (!nums)
		return ;
	i = 0;
	while (nums[i] && i < width)
	{
		z_line[i] = ft_atoi(nums[i]);
		i++;
	}
	free_split(nums);
}

void	validate_map(t_fdf *data)
{
	char	*line;
	int		fd;

	fd = open(data->file_name, O_RDONLY);
	if (fd < 0)
		error("Cannot open file", data);
	line = get_next_line(fd);
	while (line)
	{
		process_line_width(data, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	get_map_dimensions(t_fdf *data)
{
	int		fd;
	char	*line;

	data->height = 0;
	data->width = 0;
	fd = open(data->file_name, O_RDONLY);
	if (fd < 0)
		error("Cannot open file", data);
	line = get_next_line(fd);
	if (!line)
		error("empty Line", data);
	init_width(data, line);
	data->height = 1;
	line = get_next_line(fd);
	while (line)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	read_file(t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->z_matrix = NULL;
	get_map_dimensions(data);
	validate_map(data);
	data->z_matrix = create_matrix(data->height, data->width);
	if (!data->z_matrix)
		error("Matrix allocation failed", data);
	fd = open(data->file_name, O_RDONLY);
	if (fd < 0)
		error("Cannot reopen file", data);
	i = 0;
	line = get_next_line(fd);
	while (i < data->height && line)
	{
		fill_matrix_line(data->z_matrix[i], line, data->width);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}
