/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:05:03 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/19 21:36:18 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dsize;
	size_t	dsize_cpy;
	size_t	ssize;

	i = 0;
	dsize = ft_strlen(dst) + 1;
	ssize = ft_strlen(src) + 1;
	dsize_cpy = dsize;
	if (dsize > size)
		return (size + ssize - 1);
	while (dsize_cpy < size && i < ssize - 1)
	{
		dst[dsize_cpy - 1] = src[i];
		++dsize_cpy;
		++i;
	}
	dst[dsize_cpy - 1] = '\0';
	return (dsize + ssize - 2);
}
/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	char dest1[] = "0123456789";
	char src1[] = "012";
	char dest2[] = "0123456789";
	char src2[] = "012";
	
	printf("%zu %s\n", strlcat(dest1, src1, 15), dest1);
	printf("%zu %s\n", ft_strlcat(dest2, src2, 15), dest2);
}
*/
