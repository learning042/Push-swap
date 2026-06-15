/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:17:47 by jlandeir          #+#    #+#             */
/*   Updated: 2026/04/20 19:17:49 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_is_mult_overflow(size_t n, size_t m)
{
	if (m == 0)
		return (0);
	return (n > (size_t) -1 / m);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (ft_is_mult_overflow(nmemb, size))
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
