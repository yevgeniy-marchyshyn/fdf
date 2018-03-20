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

static void			draw_grid(t_fdf *data)
{
	int y;
	int x;

	y = 0;
	while (y != data->ny)
	{
		x = 0;
		while (x != data->nx)
		{
			if (x + 1 != data->nx)
			line_bresenham(data->map[y][x], data->map[y][x + 1], data);
			if (y + 1 != data->ny)
				line_bresenham(data->map[y][x], data->map[y + 1][x], data);
			x++;
		}
		y++;
	}
}

void				draw_map(t_fdf *data)
{
	if (!(data->mlx_img = mlx_new_image(data->mlx_ptr,\
	WINDOW_W, WINDOW_H)))
		fdf_error(6);
	if (!(data->field = (int*)mlx_get_data_addr(data->mlx_img,\
		&data->bits_per_pixel, &data->size_line, &data->endian)))
		fdf_error(5);
	draw_grid(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
}
