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

void	read_file(t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	data->height = 0;
	data->width = 0;
	get_dimention(data);
	check_map(data);
	data->z_matrix = create_matrix(data->height, data->width);
	if (!data->z_matrix)
		error("Malloc Matrix Error !");
	fd = open(data->file_name, O_RDONLY);
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

void	get_dimention(t_fdf *data)
{
	char	*line;
	char	**tab;
	int		fd;

	fd = open(data->file_name, O_RDONLY);
	if (fd < 0)
		error("Map Error !");
	line = get_next_line(fd);
	if (!line)
		error("Map Empty !");
	tab = ft_split(line, ' ');
	while (tab[data->width])
	{
		free(tab[data->width]);
		data->width++;
	}
	while (line)
	{
		free(line);
		data->height++;
		line = get_next_line(fd);
	}
	free(line);
	free(tab);
	close (fd);
}

void	check_map(t_fdf *data)
{
	char	**split;
	char	*line;
	int		fd;
	int		x;

	fd = open(data->file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		free(line);
		x = 0;
		while (split[x])
		{
			free(split[x]);
			x++;
		}
		free(split);
		if (x < data->width || x > data->width)
			error("Wrong Format !");
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
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
