/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:17:05 by jlandeir          #+#    #+#             */
/*   Updated: 2026/04/20 19:17:07 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*saux1;
	unsigned char	*saux2;

	i = 0;
	saux1 = (unsigned char *)s1;
	saux2 = (unsigned char *)s2;
	while (i < n)
	{
		if (saux1[i] != saux2[i])
			return (saux1[i] - saux2[i]);
		i++;
	}
	return (0);
}
