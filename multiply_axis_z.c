/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_axis_z.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:40:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/30 18:33:51 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			multiply_axis_z(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->ny)
	{
		x = 0;
		while (x < data->nx)
		{
			data->map[y][x].z *= Z_COEFFICIENT;
			data->map_origin[y][x].z *= Z_COEFFICIENT;
			x++;
		}
		y++;
	}
}
