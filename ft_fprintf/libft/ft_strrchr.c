/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:16:15 by jlandeir          #+#    #+#             */
/*   Updated: 2026/04/22 13:13:06 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*lastfound;

	i = 0;
	lastfound = NULL;
	while (s[i])
	{
		if (s[i] == (char) c)
			lastfound = (char *)s + i;
		i++;
	}
	if ((char) c == '\0')
		return ((char *)s + i);
	else
		return (lastfound);
}
