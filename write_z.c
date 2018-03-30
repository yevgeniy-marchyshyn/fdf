/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:17:05 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/30 11:17:09 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		write_z(t_fdf *data, int *x, int y, char **n)
{
	data->map[y][*x].y = (double)y - (data->ny / 2);
	data->map[y][*x].x = (double)*x - (data->nx / 2);
	data->map[y][*x].z = (double)ft_atoi(n[*x]);
	data->map_origin[y][*x].y = (double)y - (data->ny / 2);
	data->map_origin[y][*x].x = (double)*x - (data->nx / 2);
	data->map_origin[y][*x].z = (double)ft_atoi(n[*x]);
	(*x)++;
}