/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:34:30 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/14 18:54:56 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(double x, double y, t_fdf *data)
{
	int i;

	if ((x >= 0 && x < WINDOW_W) && (y >= 0 && y < WINDOW_H))
	{
		i = (int)x + ((int)y * (data->size_line / 4));
		data->field[i] = data->color;
	}
}
