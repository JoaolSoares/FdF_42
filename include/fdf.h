/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:29:49 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/05 04:58:02 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// INCLUDES
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h> 
# include <X11/X.h> 
# include <stdlib.h>
# include <math.h>
# include "../lib/include/libft.h"

# define ESC_KEY 65307
# define DEFAULT_COLOR 0xffffff

// STRUCTS
typedef struct s_camera
{
	int		zoom;
	float	angle;
	int		x_position;
	int		y_position;
	int		gap;
	int		projection;

}	t_camera;

typedef struct s_spots
{
	float	x1;
	float	y1;
	int		z1;
	float	x2;
	float	y2;
	int		z2;

}	t_spots;

typedef struct s_map
{
	int		**matrix;
	int		**color_mtx;
	int		length;
	int		width;

}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_spots	*spots;
	t_camera *camera;

}	t_fdf;

//	INIT FUNCTIONS
t_fdf	*init_allocs(void);
void	init_window(t_fdf *fdf);
void	init_matrix(t_fdf *fdf, char *file);
//	UTILS
void	pick_sizes(t_fdf *fdf, char *file);
void	convert_mtx(t_fdf *fdf, char **line);

//	DRAW FUNCTIONS
void	draw(t_fdf *fdf);
//	UTILS
int		bigger(int a, int b);
float	positive(float i);
void	isometric(float *x, float *y, int z, float angle);

//	HOOK FUNCTIONS
int		key_hook(int keycode, t_fdf *fdf);
int		x_hook(t_fdf *fdf);
int		expose_hook(t_fdf *fdf);
// int	mouse_hook(int mousecode, t_fdf *fdf);

//	DESTROY FUNCTIONS
void	destroy_window(t_fdf *fdf);
void	destroy_all(t_fdf *fdf);
void	destroy_line(char **line);

#endif

// ver os hooks novamente.
// mudar os valores dos erros dos exits.
// corrigir erros do mapa, como os nulos no começo e talz, n sei se precisa.
// ver se tenho que colocar a milibx dentro do projeto.