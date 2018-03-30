/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_before_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:57:19 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/30 18:57:33 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_before_exit(t_fdf *data)
{
	if (data->line != NULL)
		ft_strdel(&data->line);
	if (data->fat_line != NULL)
		ft_strdel(&data->fat_line);
	if (data->axis_x != NULL)
		free_words(data->axis_x);
	if (data->map != NULL)
		free(data->map);
	if (data->map_origin != NULL)
		free(data->map_origin);
}
