/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 03:43:14 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/05 04:25:49 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	pick_length(int fd)
{
	char	*buffer;
	char	**line;
	int		i;

	buffer = get_next_line(fd);
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

static int	pick_width(int fd)
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

	fd = open(file, 'r');
	fdf->map->length = pick_length(fd);
	fdf->map->width = pick_width(fd);
	close(fd);
}

void	convert_mtx(t_fdf *fdf, char **line)
{
	static int	i;
	int			j;
	char		*hexa_color;

	if (!(fdf->map->matrix[i] = malloc(sizeof(int) * fdf->map->length)) ||
		!(fdf->map->color_mtx[i] = malloc(sizeof(int) * fdf->map->length)))
		exit(1);
	j = -1;
	while (line[++j])
	{
		if ((hexa_color = ft_strchr(line[j], ',')))
			fdf->map->color_mtx[i][j] = ft_hexatoi(hexa_color + 3);
		else
			fdf->map->color_mtx[i][j] = DEFAULT_COLOR;
		fdf->map->matrix[i][j] = ft_atoi(line[j]);
	}
	i++;
}