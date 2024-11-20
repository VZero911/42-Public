/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:02 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/19 23:02:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "MiniLibX/mlx.h"

typedef struct s_fdf
{
	int		height;
	int		width;
	int		**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

void	read_file(char *file_name, t_fdf *data);
void	free_data(t_fdf *data);

#endif