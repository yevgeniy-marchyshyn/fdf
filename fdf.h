/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:25:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/18 14:07:31 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <math.h>
#include "./libft/libft.h"

#define		WINDOW_W			1024
#define		WINDOW_H			768
#define		SCALE				50

#define		COLOR_BLUE			255
#define		COLOR_GREEN			65280
#define		COLOR_CYAN			65535
#define		COLOR_RED			16711680
#define		COLOR_MAGENTA		16711935
#define		COLOR_YELLOW		16776960
#define		COLOR_WHITE			16777215
#define		COLOR_FACEBOOK		3889560	
#define		COLOR_MARS			12665870

#define		KEY_C				8
#define		KEY_ESCAPE			53
#define		ARROW_LEFT			123
#define		ARROW_RIGHT			124
#define		ARROW_UP			126
#define		ARROW_DOWN			125

#define		NEW_LINE			10
#define		SPACE				32

typedef struct		s_bresenham
{
	int				x[2];
	int				y[2];
	int				d[2];
	int				s[2];
	int				err;
	int				e2;
}					t_bresenham;

typedef	struct		s_coordinates
{
	double			x;
	double			y;
	double			z;
}					t_coordinates;


typedef struct					s_fdf
{
	void						*mlx_ptr;
	void						*mlx_window;
	void						*mlx_img;
	double 						ny;
	double 						nx;
	char 						**axis_x;
	int 						*field;
	int							bits_per_pixel;
	int							size_line;
	int							endian;
	int							color;
	double						multiplier;
	double						x_max;
	double						y_max;
	double						offset_x;
	double						offset_y;
	int							angle_x;
	int							angle_y;
	int							angle_z;
	struct s_coordinates		**map;
	struct s_coordinates		**map_origin;
}								t_fdf;

void				fdf_error(int errornumber);
int					manage_control_keys(int key, t_fdf *data);
void				draw_map(t_fdf *data);
int					click_x(t_fdf *data);
void				put_pixel(double x, double y, t_fdf *data);
void				line_bresenham(int p0, int p1, t_fdf *data);
void				apply_multiplier(t_fdf *data);
void				define_offset(t_fdf *data);

#endif
