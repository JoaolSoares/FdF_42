/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 03:22:21 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/05 05:00:23 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* -------------- ALLOC FUNCTION ---------------- */

t_fdf	*init_allocs(void)
{
	t_fdf	*fdf;

	if (!(fdf = malloc(sizeof(t_fdf))) ||
		!(fdf->map = malloc(sizeof(t_map))) ||
		!(fdf->spots = malloc(sizeof(t_spots))) ||
		!(fdf->camera = malloc(sizeof(t_camera))))
		exit(1);
	return (fdf);
}

/* -------------- MATRIX FUNCTIONS ---------------- */

void	init_matrix(t_fdf *fdf, char *file)
{
	int		fd;
	char	*buffer;
	char	**line;

	if (!(fd = open(file, 'r')))
		exit(0);
		
	pick_sizes(fdf, file);

	if (!(fdf->map->matrix = malloc(sizeof(int *) * fdf->map->width)) ||
		!(fdf->map->color_mtx = malloc(sizeof(int *) * fdf->map->width)))
		exit(1);

	buffer = get_next_line(fd);
	while (buffer)
	{
		line = ft_split(buffer, ' ');
		convert_mtx(fdf, line);
		destroy_line(line);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close (fd);
}

/* -------------- CAMERA FUNCTIONS ---------------- */

static void	init_camera(t_fdf *fdf)
{
	fdf->camera->zoom = 30;
	fdf->camera->angle = 0.8;
	fdf->camera->x_position = 330;
	fdf->camera->y_position = 120;
	fdf->camera->gap = 1;
	fdf->camera->projection = 1;
}

/* -------------- WINDOW FUNCTIONS ---------------- */

void	init_window(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		destroy_all(fdf);
		exit(1);
	}
	
	fdf->win = mlx_new_window(fdf->mlx, 800, 600, "FdF");
	if (!fdf->win)
	{
		destroy_all(fdf);
		exit(1);
	}

	init_camera(fdf);
	draw(fdf);

	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_hook(fdf->win, DestroyNotify, NoEventMask, x_hook, fdf);
	mlx_expose_hook(fdf->win, expose_hook, fdf);
	// mlx_mouse_hook(fdf->win, mouse_hook, fdf);
	mlx_loop(fdf->mlx);
}
