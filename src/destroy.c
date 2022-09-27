/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:39:40 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/09/27 23:56:46 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_line(t_fdf *fdf)
{
	int i;

	i = 0;
	while (fdf->map->line[i])
	{
		free(fdf->map->line[i]);
		i++;
	}
	free(fdf->map->line);
}

static void		free_matrix(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->map->width)
		free(fdf->map->matrix[i++]);
	free(fdf->map->matrix);
}

void	free_all(t_fdf *fdf)
{
	free_matrix(fdf);
	free(fdf->map);
	free(fdf->mlx);
	free(fdf);
}
