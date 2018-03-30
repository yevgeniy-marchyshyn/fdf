/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:25:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/30 01:05:08 by ymarchys         ###   ########.fr       */
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
#define		Z_COEFFICIENT		3

#define		COLOR_BLUE			255
#define		COLOR_GREEN			65280
#define		COLOR_CYAN			65535
#define		COLOR_RED			16711680
#define		COLOR_MAGENTA		16711935
#define		COLOR_YELLOW		16776960
#define		COLOR_WHITE			16777215
#define		COLOR_FACEBOOK		3889560	
#define		COLOR_MARS			12665870

#define		KEY_ESCAPE			53
#define		ARROW_LEFT			123
#define		ARROW_RIGHT			124
#define		ARROW_UP			126
#define		ARROW_DOWN			125
#define		KEY_PAGE_UP			116
#define		KEY_PAGE_DOWN		121
#define		KEY_A				0
#define		KEY_W				13
#define		KEY_S				1
#define		KEY_D				2
#define		KEY_PLUS			24
#define		KEY_MINUS			27

#define		KEY_ONE				18
#define		KEY_TWO				19
#define		KEY_THREE			20
#define		KEY_FOUR			21
#define		KEY_FIVE			23
#define		KEY_SIX				22
#define		KEY_SEVEN			26
#define		KEY_EIGHT			28
#define		KEY_NINE			25

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
	struct s_coordinates		**map;
	struct s_coordinates		**map_origin;
	double 						ny;
	double 						nx;
	int 						*field;						
	int							bits_per_pixel;
	int							size_line;
	int							endian;
	int							color;
	double						multiplier;
	double						offset_x;
	double						offset_y;
	int 						value_x;
	int 						value_y;
	int							angle_x;
	int							angle_y;
	int							angle_z;
	char						first_dive;
	char						*fat_line;
	char						*line;
	char						**axis_x;
}								t_fdf;

void				annulation_fdf(t_fdf *data);
void				fdf_error(int errornumber, t_fdf *data);
int					manage_control_keys(int key, t_fdf *data);
void				draw_map(t_fdf *data);
int					click_x(t_fdf *data);
void				put_pixel(double x, double y, t_fdf *data);
void				line_bresenham(t_coordinates p0, t_coordinates p2, t_fdf *d);
void				apply_multiplier(t_fdf *data);
void				set_offset(t_fdf *data);
void				reset_offset(t_fdf *data);
void				map_rotation(t_fdf *data);
void				move_map(t_fdf *data);
void 				multiply_axis_z(t_fdf *data);
void				joiner(char **fat_line, char **line);
void				annulation_pm(char **fat_line, char **line, t_fdf *data);
void				write_z(t_fdf *data, int *x, int y, char **n);
void				is_valid(int x, t_fdf *data);
void				free_before_exit(t_fdf *data);
void				z_plus(t_fdf *data, int	value);

#endif
