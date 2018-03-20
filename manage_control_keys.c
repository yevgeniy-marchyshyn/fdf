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

static void		reset_offset(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->ny)
	{
		x = 0;
		while (x < data->nx)
		{
			data->map[y][x].x -= data->offset_x;
			data->map[y][x].y -= data->offset_y;
			data->map_origin[y][x].x -= data->offset_x;
			data->map_origin[y][x].y -= data->offset_y;
			x++;
		}
		y++;
	}
}

int				manage_control_keys(int key, t_fdf *data)
{
	if (key == ARROW_UP)
		data->angle_x += 2;
	if (key == ARROW_DOWN)
		data->angle_x -= 2;
	if (key == ARROW_LEFT)
		data->angle_y += 2;
	if (key == ARROW_RIGHT)
		data->angle_y -= 2;
	if (key == KEY_PAGE_UP)
		data->angle_z += 2;
	if (key == KEY_PAGE_DOWN)
		data->angle_z -= 2;
	if (key == KEY_D)
		data->value_x += 5;
	if (key == KEY_A)
		data->value_x -= 5;
	if (key == KEY_S)
		data->value_y += 5;
	if (key == KEY_W)
		data->value_y -= 5;
	if (key == KEY_ONE)
		data->color = COLOR_BLUE;
	if (key == KEY_TWO)
		data->color = COLOR_GREEN;
	if (key == KEY_THREE)
		data->color = COLOR_CYAN;
	if (key == KEY_FOUR)
		data->color = COLOR_MAGENTA;
	if (key == KEY_FIVE)
		data->color = COLOR_YELLOW;
	if (key == KEY_SIX)
		data->color = COLOR_WHITE;
	if (key == KEY_SEVEN)
		data->color = COLOR_FACEBOOK;
	if (key == KEY_EIGHT)
		data->color = COLOR_MARS;
	if (key == KEY_NINE)
		data->color = COLOR_RED;
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		exit (1);
	}

	reset_offset(data);
	map_rotation(data);
	set_offset(data);
	move_map(data);
	draw_map(data);
	return (0);
}
