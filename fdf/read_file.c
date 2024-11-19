/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:13 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/19 05:39:03 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;
	char	**split;

	width = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	while (split[width])
	{
		free(split[width]);
		width++;
	}
	free(split);
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line, int width)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	if (!nums)
		return ;
	while (nums[i] && i < width)
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	while (nums[i])
		free(nums[i++]);
	free(nums);
}

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
			while (--i >= 0)
				free(matrix[i]);
			free(matrix);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

void	read_file(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = create_matrix(data->height, data->width);
	if (!data->z_matrix)
		return ;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		free_data(data);
		exit(1);
	}
	i = -1;
	line = get_next_line(fd);
	while (line && i++ < data->height)
	{
		fill_matrix(data->z_matrix[i], line, data->width);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
