/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 03:22:21 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/09/28 00:49:01 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free_all(fdf);
		exit(0);
	}
	//else // para o bonus
	return (0);
}

void	init_window(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		free_all(fdf);
		exit(1);
	}
	fdf->win = mlx_new_window(fdf->mlx, 800, 600, "FdF");
	if (!fdf->win)
	{
		free_all(fdf);
		exit(1);
	}

	draw_line(fdf, 400, 200, 400, 400); //dps eu só vou chamar a draw aqui e a draw_line vai ta dentro dela

	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_loop(fdf->mlx);
}

void	init_sizes(t_fdf *fdf, char *file)
{
	int	fd;
	char *buffer;
	char **line;
	int	i;
	
	fd = open(file, 'r');
	
	buffer = get_next_line(fd);
	line = ft_split(buffer, ' ');
	free (buffer);
	
	i = 0;
	while (line[i])
		free(line[i++]);
	free(line);
	fdf->map->length = i;
	
	i = 1;
	buffer = get_next_line(fd);
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(fd);
		i++;
	}
	fdf->map->width = i;
	
	close(fd);
}

static int	*convert_mtx(char **char_mtx, int size)
{
	int	*mtx;
	int	i;
	
	if (!(mtx = malloc(sizeof(int) * size)))
		exit(1);
	i = -1;
	while (char_mtx[++i])
		mtx[i] = ft_atoi(char_mtx[i]);
	return (mtx);
}

void	init_matrix(t_fdf *fdf, char *file)
{
	int		fd;
	int		i;

	fd = open(file, 'r');
	if (!(fdf->map = malloc(sizeof(t_map))))
		exit(1);
	init_sizes(fdf, file);
	if (!(fdf->map->matrix = malloc(sizeof(int *) * fdf->map->width)))
		exit(1);

	i = 0;
	fdf->map->buffer = get_next_line(fd);
	while (fdf->map->buffer)
	{
		fdf->map->line = ft_split(fdf->map->buffer, ' ');
		valid_map_line(fdf);
		fdf->map->matrix[i++] = convert_mtx(fdf->map->line, fdf->map->length);
		free_line(fdf);
		free(fdf->map->buffer);
		fdf->map->buffer = get_next_line(fd);
	}
	close (fd);
}
