/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:50:55 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/11 23:53:19 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	pixel;

	if (fdf->pixel_bits != 32)
		color = mlx_get_color_value(fdf->mlx, color);
	pixel = (y * fdf->line_bytes) + (x * 4);
	if (fdf->endian == 1)
	{
		fdf->buffer[pixel + 0] = (color >> 24);
		fdf->buffer[pixel + 1] = (color >> 16) & 0xFF;
		fdf->buffer[pixel + 2] = (color >> 8) & 0xFF;
		fdf->buffer[pixel + 3] = (color) & 0xFF;
	}
	if (fdf->endian == 0)
	{
		fdf->buffer[pixel + 0] = (color) & 0xFF;
		fdf->buffer[pixel + 1] = (color >> 8) & 0xFF;
		fdf->buffer[pixel + 2] = (color >> 16) & 0xFF;
		fdf->buffer[pixel + 3] = (color >> 24);
	}
}

static void	brasenham(t_fdf *fdf, t_spots *spots, int color)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = spots->x2 - spots->x1;
	y_step = spots->y2 - spots->y1;
	max = bigger(positive(x_step), positive(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(spots->x1 - spots->x2) || (int)(spots->y1 - spots->y2))
	{
		if ((spots->x1 * 4) <= fdf->line_bytes && \
			(spots->x1 * 4) >= 0 && \
			(spots->y1 * fdf->line_bytes) + (spots->x1 * 4) <= \
			(WIN_HEIGHT * WIN_WIDTH) * 4 && \
			spots->y1 >= 0)
			put_pixel(fdf, spots->x1, spots->y1, color);
		spots->x1 += x_step;
		spots->y1 += y_step;
	}
}

static void	draw_line(t_fdf *fdf, t_spots spots)
{
	int		color;

	color = fdf->map->color_mtx[(int)spots.y1][(int)spots.x1];
	if (fdf->map->color_mtx[(int)spots.y1][(int)spots.x1] != DEFAULT_COLOR)
		color = fdf->map->color_mtx[(int)spots.y1][(int)spots.x1];
	else if (fdf->map->color_mtx[(int)spots.y2][(int)spots.x2] != DEFAULT_COLOR)
		color = fdf->map->color_mtx[(int)spots.y2][(int)spots.x2];
	spots.z1 = fdf->map->matrix[(int)spots.y1][(int)spots.x1];
	spots.z2 = fdf->map->matrix[(int)spots.y2][(int)spots.x2];
	spots.z1 *= fdf->camera->gap;
	spots.z2 *= fdf->camera->gap;
	spots.x1 *= fdf->camera->zoom;
	spots.y1 *= fdf->camera->zoom;
	spots.x2 *= fdf->camera->zoom;
	spots.y2 *= fdf->camera->zoom;
	if (fdf->camera->projection == 1)
	{		
		isometric(&spots.x1, &spots.y1, spots.z1, fdf->camera->angle);
		isometric(&spots.x2, &spots.y2, spots.z2, fdf->camera->angle);
	}
	spots.x1 += fdf->camera->x_position;
	spots.y1 += fdf->camera->y_position;
	spots.x2 += fdf->camera->x_position;
	spots.y2 += fdf->camera->y_position;
	brasenham(fdf, &spots, color);
}

void	draw(t_fdf *fdf)
{
	init_image(fdf);
	fdf->spots->y1 = 0;
	while (fdf->spots->y1 < fdf->map->height)
	{
		fdf->spots->x1 = 0;
		while (fdf->spots->x1 < fdf->map->width)
		{
			if (fdf->spots->x1 < fdf->map->width - 1)
			{
				fdf->spots->y2 = fdf->spots->y1;
				fdf->spots->x2 = fdf->spots->x1 + 1;
				draw_line(fdf, *fdf->spots);
			}
			if (fdf->spots->y1 < fdf->map->height - 1)
			{
				fdf->spots->x2 = fdf->spots->x1;
				fdf->spots->y2 = fdf->spots->y1 + 1;
				draw_line(fdf, *fdf->spots);
			}
			fdf->spots->x1++;
		}
		fdf->spots->y1++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
