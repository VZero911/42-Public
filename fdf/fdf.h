/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:02 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/22 00:08:25 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "math.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MLX_ERROR 1
# define ISO_ANGLES 0.523599

typedef struct s_point
{
	double  x;
	double  y;
	int     z;
	int     color;
	double  delta_x;
	double  delta_y;
	int     steps;
	double  x_increment;
	double  y_increment;
}	t_point;

typedef struct s_fdf
{
	void    *mlx_ptr;
	void    *win_ptr;
	void    *image;
	char    *adress;
	char    *file_name;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
	int     width;
	int     height;
	int     **z_matrix;
	int     zoom;
	int     x;
	int     y;
	t_point current;
	t_point right;
	t_point down;
}	t_fdf;

void	read_file(t_fdf *data);
void	get_map_dimensions(t_fdf *data);
void	validate_map(t_fdf *data);
int		**create_matrix(int height, int width);
void	fill_matrix_line(int *z_line, char *line, int width);

int		data_init(t_fdf *data);

void    draw_map(t_fdf *data);

int		check_file_name(char *file_name);
void	free_matrix(int **matrix, int height);
void	free_split(char **split);
int     calculate_color(int z1, int z2);
int		error(char *str);

void	init_width(t_fdf *data, char *line);
int		count_split_elements(char **split);
void	process_line_width(t_fdf *data, char *line);
void	free_data(t_fdf *data);

#endif