/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_offset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:56:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/30 18:33:59 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		reset_offset(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->ny)
	{
		x = 0;
		while (x < data->nx)
		{
			data->map[y][x].x -= data->offset_x;
			data->map[y][x].y -= data->offset_y;
			data->map_origin[y][x].x -= data->offset_x;
			data->map_origin[y][x].y -= data->offset_y;
			x++;
		}
		y++;
	}
}
