/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:30:59 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/30 18:57:43 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		is_valid(int x, t_fdf *data)
{
	if (data->first_dive == 1 && x != data->nx)
		fdf_error(7, data);
	if (x > data->nx)
	{
		data->nx = x;
		data->first_dive = 1;
	}
}
