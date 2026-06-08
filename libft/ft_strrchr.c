/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:43:23 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/20 16:56:30 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (char) c)
			last_occurrence = (char *) s;
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (last_occurrence);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s = "teste";
	printf("%p\n", s);
	printf("%p\n", ft_strrchr(s, '\0'));
	return (0);
}
*/
