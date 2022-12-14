/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:57:40 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/05 01:39:33 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	valid_arg(int argc, char *argv)
{
	if (argc != 2)
	{
		ft_printf("ERROR! Number of arguments incorrect. Map not informed.\n");
		exit(1);
	}
	else if (!ft_strnstr(argv + ft_strlen(argv) - 4, ".fdf", 4))
	{
		ft_printf("ERROR! Map not valid. (.fdf)\n");
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	valid_arg(argc, argv[1]);
	fdf = init_allocs();
	init_matrix(fdf, argv[1]);
	init_window(fdf);
	return (0);
}
