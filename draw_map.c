/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:33:17 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/14 20:13:19 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//
//static void			define_offset(t_fdf *data)
//{
//	int		i;
//
//	i = 0;
//	data->x_max_multiplied = 0;
//	data->y_max_multiplied = 0;
//	while (i < data->last)
//	{
//		if (data->x_max_multiplied < data->map[i].x)
//			data->x_max_multiplied = data->map[i].x;
//		if (data->y_max_multiplied < data->map[i].y)
//			data->y_max_multiplied = data->map[i].y;
//		i++;
//	}
//	data->offset_x = (WINDOW_W / 2) - (data->x_max_multiplied / 2);
//	data->offset_y = (WINDOW_H / 2) - (data->y_max_multiplied / 2);
//}
//
//static void			apply_multiplier(t_fdf *data)
//{
//	int i;
//
//	i = 0;
//	data->x_max = 0;
//	data->y_max = 0;
//	while (i < data->last)
//	{
//		if (data->x_max < data->map[i].x)
//			data->x_max = data->map[i].x;
//		if (data->y_max < data->map[i].y)
//			data->y_max = data->map[i].y;
//		i++;
//	}
//	if (WINDOW_W / data->x_max > WINDOW_H / data->y_max)
//		data->factor = WINDOW_W / data->x_max;
//	else
//		data->factor = WINDOW_H / data->y_max;
//	data->factor = (data->factor / 100) * SCALE;
//	i = 0;
//	while (i < data->last)
//	{
//		data->map[i].x = data->map[i].x * (int)data->factor;
//		data->map[i].y = data->map[i].y * (int)data->factor;
//		i++;
//	}
//}
//
//static void			draw_grid(t_fdf *data)
//{
//	int		i;
//
//	i = 0;
//	while (i < data->last)
//	{
//		if (data->map[i].x != data->x_max_multiplied)
//			line_bresenham(i, i + 1, data);
//		if (data->map[i].y != data->y_max_multiplied)
//			line_bresenham(i, i + (int)data->x_max + 1, data);
//		i++;
//	}
//}
//
//void				draw_map(t_fdf *data)
//{
//	apply_multiplier(data);
//	define_offset(data);
//	if (!(data->mlx_img = mlx_new_image(data->mlx_ptr,\
//	WINDOW_W, WINDOW_H)))
//		fdf_error(6);
//	if (!(data->field = (int*)mlx_get_data_addr(data->mlx_img,\
//		&data->bits_per_pixel, &data->size_line, &data->endian)))
//		fdf_error(5);
//	data->color = COLOR_RED;
//	data->angle_x = 45;
//	data->angle_y = 45;
//	data->angle_z = 45;
////	map_rotation(data, map);
//	draw_grid(data);
//	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->mlx_img, 0, 0);
//	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
//}

//static void			draw_grid(t_fdf *data)
//{
//	int y;
//	int x;
//
//	while (y < data->ny)
//	{
//		line_bresenham()
//		while (x < data->nx)
//		{
//
//		}
//	}
//}

void				draw_map(t_fdf *data)
{
	int x = 0;
	int y = 0;

	apply_multiplier(data);
	define_offset(data);
	if (!(data->mlx_img = mlx_new_image(data->mlx_ptr,\
	WINDOW_W, WINDOW_H)))
		fdf_error(6);
	if (!(data->field = (int*)mlx_get_data_addr(data->mlx_img,\
		&data->bits_per_pixel, &data->size_line, &data->endian)))
		fdf_error(5);
	data->color = COLOR_RED;
	data->angle_x = 45;
	data->angle_y = 45;
	data->angle_z = 45;
	while (y < data->ny)
	{
		x = 0;
		while (x < data->nx)
		{
			put_pixel(data->map[y][x].x, data->map[y][x].y, data);
			x++;
		}
		y++;
	}
//	map_rotation(data, map);
//	draw_grid(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
}
