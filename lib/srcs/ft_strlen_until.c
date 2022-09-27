/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 23:43:23 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/09/13 23:44:01 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_until(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}