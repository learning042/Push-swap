/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:16:55 by jlandeir          #+#    #+#             */
/*   Updated: 2026/04/20 19:16:57 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*straux;
	unsigned char	charaux;

	i = 0;
	straux = (unsigned char *)s;
	charaux = (unsigned char) c;
	while (i < n)
	{
		if (straux[i] == charaux)
			return ((void *)(straux + i));
		i++;
	}
	return (NULL);
}
