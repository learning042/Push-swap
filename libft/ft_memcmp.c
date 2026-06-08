/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:46:59 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/14 19:23:45 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char *) s1;
	s2_cpy = (unsigned char *) s2;
	while (n--)
	{
		if (*s1_cpy != *s2_cpy)
			return (*s1_cpy - *s2_cpy);
		++s1_cpy;
		++s2_cpy;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	s1[100] = "hello";
	char	s2[21] = "hello";

	printf("%i\n", ft_memcmp(s1, s2, 5));
	printf("%i\n", ft_memcmp(s1, s2, 21));
	printf("%i\n", ft_memcmp(s1, s2, 90));
	
	return (0);
}
*/
