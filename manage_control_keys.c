/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_control_keys.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:43:12 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/12 13:48:10 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			manage_control_keys(int key, t_fdf *data)
{
	if (key == KEY_C)
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_window);
		return (1);
	}
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		exit (1);
	}
	if (key == ARROW_LEFT)
	{
		data->angle_x += 2;
//		return (1);
	}
	if (key == ARROW_RIGHT)
	{
		data->angle_x -= 2;
//		return (1);
	}
//	if (key == ARROW_UP)
//	{
//		data->angle += 2;
//	}
//	if (key == ARROW_DOWN)
//	{
//		data->angle += 2;
//	}
//	draw_map(&data, map);
	return (0);
}
