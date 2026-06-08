/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 21:05:14 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/21 17:51:47 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (src == dest)
		return (dest);
	if (d < s)
	{
		while (n--)
			*(d++) = *(s++);
	}
	else
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*(d--) = *(s--);
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
    char str[100] = "hello world";

    printf("Original string (str) : %s\n", str);
    // Using memmove on second independent copy
    ft_memmove(str, str, 10);
    printf("memmove overlap : %s\n", str);

    return 0;
}
*/
