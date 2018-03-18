/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:20:41 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/14 18:25:46 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		copy(t_fdf *data, t_bresenham *l, int p0, int p1)
{
	l->x[0] = (int)data->map[p0].x;
	l->x[1] = (int)data->map[p1].x;
	l->y[0] = (int)data->map[p0].y;
	l->y[1] = (int)data->map[p1].y;
}

void			line_bresenham(int p0, int p1, t_fdf *data)
{
	t_bresenham		line;

	copy(data, &line, p0, p1);
	line.d[0] = abs(line.x[1] - line.x[0]);
	line.s[0] = line.x[0] < line.x[1] ? 1 : -1;
	line.d[1] = abs(line.y[1] - line.y[0]);
	line.s[1] = line.y[0] < line.y[1] ? 1 : -1;
	line.err = (line.d[0] > line.d[1] ? line.d[0] : -line.d[1]) / 2;
	while (1)
	{
		put_pixel(line.x[0], line.y[0], data);
		if (line.x[0] == line.x[1] && line.y[0] == line.y[1])
			break ;
		line.e2 = line.err;
		if (line.e2 > -line.d[0])
		{
			line.err = line.err - line.d[1];
			line.x[0] = line.x[0] + line.s[0];
		}
		if (line.e2 < line.d[1])
		{
			line.err = line.err + line.d[0];
			line.y[0] = line.y[0] + line.s[1];
		}
	}
}
