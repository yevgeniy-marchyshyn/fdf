/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:56:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/30 18:41:21 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void				map_rotation_x(t_fdf *data)
{
	int				x;
	int				y;
	double			radian;

	y = 0;
	radian = data->angle_x * M_PI / 180;
	while (y < data->ny)
	{
		x = 0;
		while (x < data->nx)
		{
			data->map[y][x].y = data->map_origin[y][x].y * cos(radian) +\
			data->map_origin[y][x].z * sin(radian);
			data->map[y][x].z = -data->map_origin[y][x].y * sin(radian) +\
			data->map_origin[y][x].z * cos(radian);
			x++;
		}
		y++;
	}
}

static void				map_rotation_y(t_fdf *data)
{
	int				x;
	int				y;
	double			radian;

	y = 0;
	radian = data->angle_y * M_PI / 180;
	while (y < data->ny)
	{
		x = 0;
		while (x < data->nx)
		{
			data->map[y][x].x = data->map_origin[y][x].x * cos(radian) +\
			data->map[y][x].z * sin(radian);
			data->map[y][x].z = -data->map_origin[y][x].x * sin(radian) +\
			data->map[y][x].z * cos(radian);
			x++;
		}
		y++;
	}
}

static void				map_rotation_z(t_fdf *data)
{
	int				x;
	int				y;
	double			radian;

	y = 0;
	radian = data->angle_z * M_PI / 180;
	while (y < data->ny)
	{
		x = 0;
		while (x < data->nx)
		{
			data->map[y][x].x = data->map[y][x].x * cos(radian) -\
			data->map[y][x].y * sin(radian);
			data->map[y][x].y = data->map_origin[y][x].x * sin(radian) +\
			data->map[y][x].y * cos(radian);
			x++;
		}
		y++;
	}
}

void					map_rotation(t_fdf *data)
{
	map_rotation_x(data);
	map_rotation_y(data);
	map_rotation_z(data);
}
