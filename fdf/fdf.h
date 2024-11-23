/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:50:02 by jdumay            #+#    #+#             */
/*   Updated: 2024/11/23 07:57:20 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/XKBlib.h>
# include "math.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MAX_SHIFT (WIN_WIDTH / 2)
# define MLX_ERROR 1
# define ISO_ANGLES 0.523599
# define Event_close 17
# define MOUSE_WHEEL_DOWN 4
# define MOUSE_WHEEL_UP 5
# define ZOOM_FACTOR 1.1
# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define KEY_Q XK_q
# define KEY_E XK_e
# define KEY_P XK_p
# define KEY_I XK_i
# define KEY_SPACE XK_space
# define KEY_ESC XK_Escape
# define MOVE_SPEED 2
# define ROTATE_ANGLE 0.1
# define KEY_UP      65362
# define KEY_DOWN    65364
# define KEY_LEFT    65361
# define KEY_RIGHT   65363

typedef enum e_projection
{
    ISO = 1,
    PARALLEL = 2,
	TOP = 3,
    MILITARY = 4,
    CABINET = 5
}	t_projection;

typedef struct s_point
{
	double  x;
	double  y;
	int     z;
	int     color;
    int		init_color;
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
	int		**color_matrix;
	double     zoom;
	int     x;
	int     y;
	int		shift_x;
	int		shift_y;
	double rotation_x;
    double rotation_y;
    double rotation_z;
	t_point current;
	t_point right;
	t_point down;
	t_projection projection;
}	t_fdf;

void	read_file(t_fdf *data);
void	get_map_dimensions(t_fdf *data);
void	validate_map(t_fdf *data);
int		**create_matrix(int height, int width);
void	fill_matrix_line(int *z_line, char *line, int width);

int		data_init(t_fdf *data);
int		error(char *str);

void    draw_map(t_fdf *data);
int		handle_close(t_fdf *data);
int		process_space(int keysym, t_fdf *data);

int		check_file_name(char *file_name);
void	free_matrix(int **matrix, int height);
void	free_split(char **split);
int     calculate_color(int z1, int z2);

void	init_width(t_fdf *data, char *line);
int		count_split_elements(char **split);
void	process_line_width(t_fdf *data, char *line);
void	free_data(t_fdf *data);

t_point	project_parallel(double x, double y, double z, t_fdf *data);
t_point	project_isometric(double x, double y, double z, t_fdf *data);
t_point project_top(double x, double y, double z, t_fdf *data);
t_point project_military(double x, double y, double z, t_fdf *data);
t_point project_cabinet(double x, double y, double z, t_fdf *data);

#endif