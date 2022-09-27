/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:50:55 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/09/28 00:57:06 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2)
{
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0)
		return (1);


	while (y1 <= y2)
		mlx_pixel_put(fdf->mlx, fdf->win, x1, y1++, 0xffffff);

		
	return (0);
}

// int		draw() {}







// struct color;
// {
// 	x
// 	y
// 	color
// }

// if (x = color->x && y = color->y)
// {
// 	bota_pixel(x, y, color->color);
// 	color++;
// }
// else
// 	bota_pixel(x, y, branco);