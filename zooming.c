/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zooming.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:43:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/30 16:43:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			unset_multiplier(t_fdf *data, int x, int y)
{
	data->map[y][x].x /= data->multiplier;
	data->map[y][x].y /= data->multiplier;
	data->map[y][x].z /= data->multiplier;
	data->map_origin[y][x].x /= data->multiplier;
	data->map_origin[y][x].y /= data->multiplier;
	data->map_origin[y][x].z /= data->multiplier;
}

static void			multiply_on_value(t_fdf *data, int x, int y, double value)
{
	data->map[y][x].x *= value;
	data->map[y][x].y *= value;
	data->map[y][x].z *= value;
	data->map_origin[y][x].x *= value;
	data->map_origin[y][x].y *= value;
	data->map_origin[y][x].z *= value;
}

static void			divide_on_value(t_fdf *data, int x, int y, double value)
{
	data->map[y][x].x /= value;
	data->map[y][x].y /= value;
	data->map[y][x].z /= value;
	data->map_origin[y][x].x /= value;
	data->map_origin[y][x].y /= value;
	data->map_origin[y][x].z /= value;
}

static void			set_multiplier(t_fdf *data, int x, int y)
{
	data->map[y][x].x *= data->multiplier;
	data->map[y][x].y *= data->multiplier;
	data->map[y][x].z *= data->multiplier;
	data->map_origin[y][x].x *= data->multiplier;
	data->map_origin[y][x].y *= data->multiplier;
	data->map_origin[y][x].z *= data->multiplier;
}

void				zooming(t_fdf *data, int flag, double value)
{
	int x;
	int y;

	y = 0;
	while (y != data->ny)
	{
		x = 0;
		while (x != data->nx)
		{
			unset_multiplier(data, x, y);
			if (flag == 1)
				multiply_on_value(data, x, y, value);
			else
				divide_on_value(data, x, y, value);
			set_multiplier(data, x, y);
			x++;
		}
		y++;
	}
}