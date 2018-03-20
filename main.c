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

static void			parse_z(t_fdf *data, char *fat_line)
{
	int			x;
	int			y;
	char 		**l;
	char 		**n;

	y = 0;
	if (!(l = ft_strsplit(fat_line, NEW_LINE)))
		fdf_error(5);
	while (y < data->ny)
	{
		x = 0;
		if (!(n = ft_strsplit(l[y], SPACE)))
			fdf_error(5);
		while (x < data->nx)
		{
			data->map[y][x].y = (double)y - (data->ny / 2);
			data->map[y][x].x = (double)x - (data->nx / 2);
			data->map[y][x].z = (double)ft_atoi(n[x]);
			data->map_origin[y][x].y = (double)y - (data->ny / 2);
			data->map_origin[y][x].x = (double)x - (data->nx / 2);
			data->map_origin[y][x].z = (double)ft_atoi(n[x]);
			x++;
		}
		free(n);
		y++;
	}
	free_words(l);
}

static void 		get_coordinates(t_fdf *data, char *fat_line)
{
	int i;

	i = 0;
	if (!(data->map = (t_coordinates**)malloc(sizeof(t_coordinates*) * (int)data->ny)))
		fdf_error(5);
	if (!(data->map_origin = (t_coordinates**)malloc(sizeof(t_coordinates*) * (int)data->ny)))
		fdf_error(5);
	while (i < data->ny)
	{
		data->map[i] = (t_coordinates *)malloc(sizeof(t_coordinates) * (int)data->nx);
		data->map_origin[i++] = (t_coordinates *)malloc(sizeof(t_coordinates) * (int)data->nx + 1);
	}
	parse_z(data, fat_line);
}

static void			parse_map(char *mapname, t_fdf *data)
{
	int 		fd;
	char 		*fat_line;
	char 		*line;
	char 		**axis_x;
	int 		x;
	char 		*tmp;

	line = NULL;
	fat_line = NULL;
	data->ny = 0;
	data->nx = 0;
	if ((fd = open(mapname, O_RDONLY)) == -1)
		fdf_error(4);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		data->ny++;
		if (fat_line == NULL)
			fat_line = ft_strdup(line);
		else
		{
			tmp = ft_strjoin(fat_line, "\n");
			fat_line = ft_strjoin(tmp, line);
			ft_strdel(&tmp);
		}
		axis_x = ft_strsplit(line, SPACE);
		while (axis_x[x])
			x++;
		if (x > data->nx)
			data->nx = x;
		free(axis_x);
		ft_strdel(&line);
	}
	get_coordinates(data, fat_line);
}

int					main(int argc, char **argv)
{
	t_fdf			data;

	if (argc != 2)
		fdf_error(1);
	if (!(data.mlx_ptr = mlx_init()))
		fdf_error(2);
	if (!(data.mlx_window = mlx_new_window(data.mlx_ptr,\
					WINDOW_W, WINDOW_H, "Fils de fer (FDF)")))
		fdf_error(3);
	data.value_x = 0;
	data.value_y = 0;
	data.angle_x = 0;
	data.angle_y = 0;
	data.angle_z = 0;
	data.color = COLOR_FACEBOOK;
	parse_map(argv[1], &data);
	apply_multiplier(&data);
	set_offset(&data);
	multiply_axis_z(&data);
	draw_map(&data);
	mlx_hook(data.mlx_window, 2, 5, manage_control_keys, &data);
	mlx_hook(data.mlx_window, 17, 1L<<17, click_x, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
