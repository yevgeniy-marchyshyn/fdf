/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annulation_pm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 01:08:07 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/30 01:08:10 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		annulation_pm(char **fat_line, char **line, t_fdf *data)
{
	*line = NULL;
	*fat_line = NULL;
	data->ny = 0;
	data->nx = 0;
}

