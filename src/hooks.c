/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 02:56:24 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/11 23:47:39 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		destroy_window(fdf);
	else if (keycode == RIGHT_KEY)
		fdf->camera->x_position += 10;
	else if (keycode == DOWN_KEY)
		fdf->camera->y_position += 10;
	else if (keycode == LEFT_KEY)
		fdf->camera->x_position -= 10;
	else if (keycode == UP_KEY)
		fdf->camera->y_position -= 10;
	else if (keycode == 111)
		fdf->camera->gap++;
	else if (keycode == 108)
		fdf->camera->gap--;
	else if (keycode == I_KEY)
		fdf->camera->projection = 1;
	else if (keycode == P_KEY)
		fdf->camera->projection = 2;
	mlx_destroy_image(fdf->mlx, fdf->img);
	draw(fdf);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	if (button == 5 && fdf->camera->zoom > 1.5)
		fdf->camera->zoom -= 0.5;
	if (button == 4)
		fdf->camera->zoom += 0.5;
	if (!x && !x)
		x = y;
	mlx_destroy_image(fdf->mlx, fdf->img);
	draw(fdf);
	return (0);
}

int	x_hook(t_fdf *fdf)
{
	destroy_window(fdf);
	return (0);
}

int	expose_hook(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	draw(fdf);
	return (0);
}

void	get_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_mouse_hook(fdf->win, mouse_hook, fdf);
	mlx_hook(fdf->win, DestroyNotify, NoEventMask, x_hook, fdf);
	mlx_expose_hook(fdf->win, expose_hook, fdf);
	mlx_loop(fdf->mlx);
}
