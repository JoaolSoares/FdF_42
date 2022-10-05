/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 02:56:24 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/05 05:01:58 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		destroy_window(fdf);
	else if (keycode == 65361)
		fdf->camera->x_position += 10;
	else if (keycode == 65362)
		fdf->camera->y_position += 10;
	else if (keycode == 65363)
		fdf->camera->x_position -= 10;
	else if (keycode == 65364)
		fdf->camera->y_position -= 10;
	else if (keycode == 106)
		fdf->camera->zoom++;
	else if (keycode == 107)
		fdf->camera->zoom--;
	else if (keycode == 111)
		fdf->camera->gap++;
	else if (keycode == 108)
		fdf->camera->gap--;
	else if (keycode == 105)
		fdf->camera->projection = 1;
	else if (keycode == 112)
		fdf->camera->projection = 2;
	// ft_printf("%i\n", keycode); //tirar
	mlx_clear_window(fdf->mlx, fdf->win);
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
	draw(fdf);
	return (0);
}


// int	mouse_hook(int mousecode, t_fdf *fdf)
// {
// 	if (mousecode == 4)
// 		fdf->map->zoom++;
// 	else if (mousecode == 5)
// 		fdf->map->zoom--;
// 	ft_printf("mouse: %i \n", mousecode);
// 	ft_printf("zoom: %i \n", fdf->map->zoom);
	
// 	// mlx_clear_window(fdf->mlx, fdf->win);
// 	// draw(fdf);
// 	return (0);
// }
