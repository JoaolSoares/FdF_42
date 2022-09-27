/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:35:47 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/06/15 18:51:46 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char c = 'a';
	printf("Esperado: %d\n", isalpha(c));
	printf("Resultad: %d\n", ft_isalpha(c));
	
	return 0;
}
*/