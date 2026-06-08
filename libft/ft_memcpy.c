/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 21:42:22 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/13 12:09:13 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char *arr = NULL;
	char arr2[6] = "hello";
	int a = 20;
	int b = 10;

	// ft_memcpy(arr2, arr, 3);
	// memcpy(arr2, arr, 3);
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", arr2[i]);
	}

	ft_memcpy(&b, &a, sizeof(int));
	printf("%d\n", b);
}
*/
