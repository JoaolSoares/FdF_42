/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:57:40 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/09/28 00:47:10 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/fdf.h"


int	main(int argc, char *argv[])
{
	t_fdf	*fdf;
	
	//arg valitadion
	valid_arg(argc, argv[1]);

	//malloc
	if (!(fdf = malloc(sizeof(t_fdf))))
		exit(1);

	//matrix / map
	init_matrix(fdf, argv[1]);
	//print_mtx(fdf->map->matrix, fdf->map->width, fdf->map->length);

	//init
	init_window(fdf);

	return (0);
}
