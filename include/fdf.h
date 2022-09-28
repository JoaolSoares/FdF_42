/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:29:49 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/09/28 02:36:28 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// INCLUDES
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include "../lib/include/libft.h"

# define ESC_KEY 65307

// STRUCTS
typedef struct s_pixel
{
	int x;
	int y;
	int color;

}	t_pixel;

typedef struct s_map
{
	int		**matrix;
	char	*buffer;
	char	**line;
	int 	length;
	int		width;

}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;

}	t_fdf;

// VALIDATION FUNCTIONS
void	valid_arg(int argc, char *argv);
void	valid_map_line(t_fdf *fdf);

// INIT FUNCTIONS
void	init_window(t_fdf *fdf);
void	init_sizes(t_fdf *fdf, char *file);
void	init_matrix(t_fdf *fdf, char *file);

// DEESTROY FUNCTIONS
void	free_all(t_fdf *fdf);
void	free_line(t_fdf *fdf);

// DRAW FUNCTIONS
void	draw_line(t_fdf *fdf, float x1, float y1, float x2, float y2);

// TESTES
void	print_line(int *mtx, int size);
void	print_mtx(int **mtx, int wid, int len);

#endif

// mudar os valores dos erros dos exits