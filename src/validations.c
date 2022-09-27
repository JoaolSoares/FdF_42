/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:52:49 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/09/28 00:43:52 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	valid_arg(int argc, char *argv)
{
	if (argc != 2)
	{
		ft_printf("ERROR! Number of arguments incorrect. Map not informed.\n");
		exit(1);
	}
	else if (!ft_strnstr(argv, ".fdf", ft_strlen(argv)))
	{
		ft_printf("ERROR! Map not valid. (.fdf)\n");
		exit(1);
	}
}

void	valid_map_line(t_fdf *fdf) //vai ver se o mapa é um quadrado certo
{
	int	i;

	i = 0;
	while (fdf->map->line[i])
		i++;
	if (i != fdf->map->length)
	{
		ft_printf("ERROR! Map not valid. (it's not a square)\n");
		free_line(fdf);
		exit (1);
	}
}
