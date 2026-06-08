/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:03:16 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/21 14:16:09 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
if n * m > size_max. For getting the size_max of the type size_t
 we just need to cast the -1 for size_t, because size_t can't be 
negative, so it will go up to size_max. So, we have n > (size_t) -1 / m
*/
static int	ft_multip_overflow(size_t n, size_t m)
{
	if (m == 0)
		return (0);
	return (n > (size_t) -1 / m);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (ft_multip_overflow(nmemb, size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	int	*arr = ft_calloc(5, 2);
	for (int i = 0; i < 11; i++)
	{
		printf("%i: %i\n", i, arr[i]);
	}
	free(arr);
	return (0);
}
*/
