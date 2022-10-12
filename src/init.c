/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 03:22:21 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 02:47:16 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* -------------- ALLOC FUNCTION ---------------- */

t_fdf	*init_allocs(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	fdf->map = malloc(sizeof(t_map));
	fdf->spots = malloc(sizeof(t_spots));
	fdf->camera = malloc(sizeof(t_camera));
	if (!(fdf) || !(fdf->map) || !(fdf->spots) || !(fdf->camera))
		exit(1);
	return (fdf);
}

/* -------------- MATRIX FUNCTIONS ---------------- */

void	init_matrix(t_fdf *fdf, char *file)
{
	int		fd;
	char	*buffer;
	char	**line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		destroy_init_allocs(fdf);
		exit(1);
	}
	pick_sizes(fdf, file);
	fdf->map->matrix = malloc(sizeof(int *) * fdf->map->height);
	fdf->map->color_mtx = malloc(sizeof(int *) * fdf->map->height);
	if (!(fdf->map->matrix) || !(fdf->map->color_mtx))
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
	fdf->camera->zoom = init_zoom(fdf->map->width);
	fdf->camera->angle = 0.8;
	fdf->camera->x_position = 300;
	fdf->camera->y_position = 120;
	fdf->camera->gap = 10;
	fdf->camera->projection = 1;
}

/* -------------- IMAGE FUNCTIONS ---------------- */

void	init_image(t_fdf *fdf)
{	
	fdf->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img)
	{
		destroy_all(fdf);
		exit(1);
	}
	fdf->buffer = mlx_get_data_addr(fdf->img, &fdf->pixel_bits, \
			&fdf->line_bytes, &fdf->endian);
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
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (!fdf->win)
	{
		destroy_all(fdf);
		exit(1);
	}
	init_camera(fdf);
	draw(fdf);
	get_hooks(fdf);
}
