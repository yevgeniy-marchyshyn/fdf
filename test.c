/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarchys <ymarchys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:15:50 by ymarchys          #+#    #+#             */
/*   Updated: 2018/03/20 19:28:48 by ymarchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <locale.h>

int		main(void)
{
	wchar_t c;

	setlocale(LC_ALL, "");
	c = L'Р';
	printf("ret: %d\n", printf("%d\n", c));
	return (0);
}
