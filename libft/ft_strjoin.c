/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:08:37 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/19 20:58:44 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[i + j] = s2[i];
		i++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_cat;

	s_cat = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s_cat == NULL)
		return (NULL);
	s_cat[0] = '\0';
	ft_strcat(s_cat, s1);
	ft_strcat(s_cat, s2);
	return (s_cat);
}
/*
#include <stdio.h>
int	main(void)
{
	char const	*s1 = "hello";
	char const	*s2 = " world";
	char const	*s3 = ft_strjoin(s1, s2);
	printf("%s\n", s3);
	return (0);
}
*/
