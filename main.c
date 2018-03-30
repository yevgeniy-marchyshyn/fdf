/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:51:47 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/14 20:29:47 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			parse_z(t_fdf *data)
{
	int			x;
	int			y;
	char 		**l;
	char 		**n;

	y = 0;
	if (!(l = ft_strsplit(data->fat_line, NEW_LINE)))
		fdf_error(5, data);
	while (y < data->ny)
	{
		x = 0;
		if (!(n = ft_strsplit(l[y], SPACE)))
			fdf_error(5, data);
		while (x < data->nx)
			write_z(data, &x, y, n);
		free(n);
		y++;
	}
	free_words(l);
	ft_strdel(&data->fat_line);
}

static void 		get_coordinates(t_fdf *data)
{
	int i;

	i = 0;
	if (!(data->map = (t_coordinates**)malloc(sizeof(t_coordinates*) *\
	(int)data->ny)))
		fdf_error(5, data);
	if (!(data->map_origin = (t_coordinates**)malloc(sizeof(t_coordinates*) *\
	(int)data->ny)))
		fdf_error(5, data);
	while (i < data->ny)
	{
		data->map[i] = (t_coordinates *)malloc(sizeof(t_coordinates) *\
		(int)data->nx);
		data->map_origin[i++] = (t_coordinates *)malloc(sizeof(t_coordinates) *\
		(int)data->nx + 1);
	}
	parse_z(data);
}

static void			parse_map(char *mapname, t_fdf *data)
{
	int 		fd;
	int 		x;

	if ((fd = open(mapname, O_RDONLY)) == -1)
		fdf_error(4, data);
	while (get_next_line(fd, &data->line) > 0)
	{
		x = 0;
		data->ny++;
		if (data->fat_line == NULL)
			data->fat_line = ft_strdup(data->line);
		else
			joiner(&data->fat_line, &data->line);
		data->axis_x = ft_strsplit(data->line, SPACE);
		while (data->axis_x[x])
			x++;
		is_valid(x, data);
		free(data->axis_x);
		ft_strdel(&data->line);
	}
	if (data->nx == 0 && data->ny == 0)
		fdf_error(7, data);
	get_coordinates(data);
}

int					main(int argc, char **argv)
{
	t_fdf			data;

	annulation_fdf(&data);
	if (argc != 2)
		fdf_error(1, &data);
	if (!(data.mlx_ptr = mlx_init()))
		fdf_error(2, &data);
	if (!(data.mlx_window = mlx_new_window(data.mlx_ptr,\
					WINDOW_W, WINDOW_H, "Fils de fer (FDF)")))
		fdf_error(3, &data);
	parse_map(argv[1], &data);
	apply_multiplier(&data);
	multiply_axis_z(&data);
	map_rotation(&data);
	set_offset(&data);
	draw_map(&data);
	mlx_hook(data.mlx_window, 2, 5, manage_control_keys, &data);
	mlx_hook(data.mlx_window, 17, 1L << 17, click_x, &data);
	mlx_loop(data.mlx_ptr);
	if (data.field != NULL)
		free(data.field);
	return (0);
}
