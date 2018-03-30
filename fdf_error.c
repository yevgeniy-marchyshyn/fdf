/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:20:52 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/13 15:50:57 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_error(int errornumber, t_fdf *data)
{
	if (errornumber == 1)
		write(2, "usage: ./fdf <mapfile.fdf>\n", 27);
	else if (errornumber == 2)
		write(2, "Error: Couldn't initialize MLX connection\n", 43);
	else if (errornumber == 3)
		write(2, "Error: Couldn't create a window\n", 33);
	else if (errornumber == 4)
		write(2, "Error: Couldn't open a mapfile\n", 31);
	else if (errornumber == 5)
		write(2, "Error: Oops, something went wrong\n", 34); 
	else if (errornumber == 6)
		write(2, "Error: Couldn't create a new image\n", 35);
	else if (errornumber == 7)
		write(2, "Error: Map is not valid\n", 24);
	free_before_exit(data);
	exit (1);
}
