/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:35:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/20 16:35:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_map(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->ny)
	{
		x = 0;
		while (x < data->nx)
		{
			data->map[y][x].x += data->value_x;
			data->map[y][x].y += data->value_y;
			x++;
		}
		y++;
	}
}
