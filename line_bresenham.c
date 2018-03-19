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

static void		copy(t_bresenham *l, t_coordinates *p0, t_coordinates *p1)
{
	l->x[0] = (int)p0->x;
	l->x[1] = (int)p1->x;
	l->y[0] = (int)p0->y;
	l->y[1] = (int)p1->y;
}

void			line_bresenham(t_coordinates p0, t_coordinates p1, t_fdf *d)
{
	t_bresenham		line;

	copy(&line, &p0, &p1);
	line.d[0] = abs(line.x[1] - line.x[0]);
	line.s[0] = line.x[0] < line.x[1] ? 1 : -1;
	line.d[1] = abs(line.y[1] - line.y[0]);
	line.s[1] = line.y[0] < line.y[1] ? 1 : -1;
	line.err = (line.d[0] > line.d[1] ? line.d[0] : -line.d[1]) / 2;
	while (1)
	{
		put_pixel(line.x[0], line.y[0], d);
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
