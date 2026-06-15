/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:10:25 by jlandeir          #+#    #+#             */
/*   Updated: 2026/04/20 19:10:29 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	len_big;
	size_t	len_small;
	size_t	i;

	len_big = ft_strlen(big);
	len_small = ft_strlen(small);
	i = 0;
	if (len > len_big)
		len = len_big;
	while (i + len_small <= len)
	{
		if (ft_memcmp((char *)big + i, small, len_small) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
