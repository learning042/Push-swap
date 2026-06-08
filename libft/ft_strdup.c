/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 22:51:03 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/19 20:05:37 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*s_cpy;

	s_cpy = (char *) malloc(ft_strlen(s) + 1);
	if (s_cpy == NULL)
		return (NULL);
	ft_strcpy(s_cpy, s);
	return (s_cpy);
}
/*#include <stdio.h>
int	main(void)
{
	const char	*s = "hello";
	char	*s2 = ft_strdup(s);
	printf("%s\n", s2);
	free(s2);
	return (0);
}*/
