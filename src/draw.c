/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:50:55 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/09/28 02:51:11 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float positive(float i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

void	draw_line(t_fdf *fdf, float x1, float y1, float x2, float y2)
{
	float	x_step;
	float	y_step;
	int		max;

	// [1:1] [3:12]
	x_step = x2 - x1; // 2
	y_step = y2 - y1; // 11

	max = bigger(positive(x_step), positive(y_step)); // 11
	
	x_step /= max; //  2/11     = 0,18181818...
	y_step /= max; // 11/11     = 1

	while ((int)(x1 != x2) || (int)(y1 != y2))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x1, y1, 0xffffff);
		x1 += x_step; // 1,1818...
		y1 += y_step; // 2
	}
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