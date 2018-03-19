/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_multiplier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:58:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/18 16:58:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			apply_multiplier(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	if (WINDOW_W / data->nx > WINDOW_H / data->ny)
		data->multiplier = WINDOW_W / data->nx;
	else
		data->multiplier = WINDOW_H / data->ny;
	data->multiplier = (data->multiplier / 100) * SCALE;
	while (y < data->ny)
	{
		x = 0;
		while (x < data->nx)
		{
			data->map[y][x].x *= (int)data->multiplier;
			data->map[y][x].y *= (int)data->multiplier;
			data->map_origin[y][x].x *= (int)data->multiplier;
			data->map_origin[y][x].y *= (int)data->multiplier;
			x++;
		}
		y++;
	}
}
