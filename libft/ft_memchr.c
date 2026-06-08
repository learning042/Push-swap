/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:23:11 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/20 17:01:19 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	s2 = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (s2[i] == (unsigned char) c)
			return ((void *)(s2 + i));
		++i;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[50] = "hello";
	printf("%p\n", str);
	printf("%p\n", ft_memchr(str, 'l', 100000));
	printf("%p\n", ft_memchr(str, 'a', 100000));
	return (0);
}
*/
