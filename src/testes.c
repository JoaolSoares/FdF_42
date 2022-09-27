/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:27:42 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/09/28 00:56:59 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void print_line(int *mtx, int size)
{
	int i = 0;
	while (i < size - 1)
	{
		if (mtx[i + 1] > 9)
			ft_printf("%i ", mtx[i++]);
		else
			ft_printf("%i  ", mtx[i++]);
	}
	ft_printf("\n");
}

void print_mtx(int **mtx, int wid, int len)
{
	int i = 0;
	while (i < wid)
		print_line(mtx[i++], len);
}
