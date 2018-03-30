/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_plus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:16:14 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/30 18:38:42 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		z_plus(t_fdf *data, int value)
{
	int x;
	int y;

	y = 0;
	while (y != data->ny)
	{
		x = 0;
		while (x != data->nx)
		{
			if (data->map[y][x].z != 0)
				data->map[y][x].z += value;
			if (data->map_origin[y][x].z != 0)
				data->map_origin[y][x].z += value;
			x++;
		}
		y++;
	}
}
