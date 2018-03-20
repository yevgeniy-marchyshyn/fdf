/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annulation_fdf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:00:00 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/20 20:00:00 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		annulation_fdf(t_fdf *data)
{
	data->map = NULL;
	data->map_origin = NULL;
	data->color = COLOR_RED;
	data->value_x = 0;
	data->value_y = 0;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
}
