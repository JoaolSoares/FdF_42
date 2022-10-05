/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:39:40 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/05 01:50:46 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void destroy_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	mlx_loop_end(fdf->mlx);
	destroy_all(fdf);
	exit(0);
}

void	destroy_line(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}

static void	destroy_matrix(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->map->width)
	{
		free(fdf->map->matrix[i]);
		free(fdf->map->color_mtx[i++]);
	}
	free(fdf->map->matrix);
	free(fdf->map->color_mtx);
}

void	destroy_all(t_fdf *fdf)
{
	destroy_matrix(fdf);
	free(fdf->map);
	free(fdf->camera);
	free(fdf->spots);
	free(fdf->mlx);
	free(fdf);
}
