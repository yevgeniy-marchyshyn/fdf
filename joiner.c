/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joiner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 01:01:42 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/30 01:01:51 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		joiner(char **fat_line, char **line)
{
	char *tmp;

	tmp = NULL;
	tmp = ft_strjoin(*fat_line, "\n");
	*fat_line = ft_strjoin(tmp, *line);
	ft_strdel(&tmp);
}