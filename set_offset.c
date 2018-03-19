/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:34:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/19 15:34:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			set_offset(t_fdf *data)
{
	int		x;
	int 	y;

	y = 0;
	data->offset_x = (WINDOW_W / 2);
	data->offset_y = (WINDOW_H / 2);
//	data->offset_x = (WINDOW_W / 2) - ((data->nx * data->multiplier) / 2);
//	data->offset_y = (WINDOW_H / 2) - ((data->ny * data->multiplier) / 2);
	while (y < data->ny)
	{
		x = 0;
		while (x < data->nx)
		{
			data->map[y][x].x += data->offset_x;
			data->map[y][x].y += data->offset_y;
			data->map_origin[y][x].x += data->offset_x;
			data->map_origin[y][x].y += data->offset_y;
			x++;
		}
		y++;
	}
}
