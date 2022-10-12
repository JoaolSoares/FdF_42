/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 03:43:14 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 02:43:24 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	pick_width(int fd)
{
	char	*buffer;
	char	**line;
	int		i;

	buffer = get_next_line(fd);
	if (!buffer)
		return (-1);
	while (!buffer)
		buffer = get_next_line(fd);
	line = ft_split(buffer, ' ');
	free(buffer);
	i = 0;
	while (line[i])
		free(line[i++]);
	free(line);
	return (i);
}

static int	pick_height(int fd)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = get_next_line(fd);
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(fd);
		i++;
	}
	return (i);
}

void	pick_sizes(t_fdf *fdf, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	fdf->map->width = pick_width(fd);
	fdf->map->height = pick_height(fd);
	close(fd);
	if (fdf->map->width <= 0 || fdf->map->height <= 0)
	{	
		destroy_init_allocs(fdf);
		exit(1);
	}
}

void	convert_mtx(t_fdf *fdf, char **line)
{
	static int	i;
	int			j;
	char		*hexa_color;

	fdf->map->matrix[i] = malloc(sizeof(int) * fdf->map->width);
	fdf->map->color_mtx[i] = malloc(sizeof(int) * fdf->map->width);
	if (!(fdf->map->matrix[i]) || !(fdf->map->color_mtx[i]))
		exit(1);
	j = -1;
	while (line[++j])
	{
		hexa_color = ft_strchr(line[j], ',');
		if (hexa_color)
			fdf->map->color_mtx[i][j] = ft_hexatoi(hexa_color + 3);
		else
			fdf->map->color_mtx[i][j] = DEFAULT_COLOR;
		fdf->map->matrix[i][j] = ft_atoi(line[j]);
	}
	i++;
}

float	init_zoom(int width)
{
	if (width <= 15)
		return (40);
	else if (width > 15 && width <= 20)
		return (35);
	else if (width > 20 && width <= 50)
		return (18);
	else if (width > 50 && width <= 70)
		return (15);
	else if (width > 70 && width <= 90)
		return (13);
	else if (width > 90 && width <= 140)
		return (5);
	else if (width > 140 && width <= 220)
		return (3.5);
	return (1.5);
}
