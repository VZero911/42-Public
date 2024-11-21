/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:02 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/21 04:39:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "MiniLibX/mlx.h"
# include "math.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MLX_ERROR 1

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;

	char	*file_name;
	int		height;
	int		width;
	int		**z_matrix;
}	t_fdf;

void	read_file(t_fdf *data);
void    get_dimention(t_fdf *data);
void    check_map(t_fdf *data);
int		**create_matrix(int height, int width);
void	fill_matrix(int *z_line, char *line, int width);

int		data_init(t_fdf *data);

int		check_file_name(char *file_name);
void	free_data(t_fdf *data);
int		error(char *str);

#endif