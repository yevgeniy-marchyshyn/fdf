/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:56:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/15 19:56:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void				map_rotation_z()
{

}

static void				map_rotation_y()
{

}

static void				map_rotation_x(t_coordinates **map, t_fdf *data)
{
	int				i;
	double			radian;

	i = 0;
	radian = data->angle_x * (180 / M_PI);
	while (i < data->last)
	{
		(*map)[i].x =
	}
}

void					map_rotation(_coordinates **map, data)
{
	map_rotation_x(map, data);
	map_rotation_y(map, data);
	map_rotation_z(map, data);
}