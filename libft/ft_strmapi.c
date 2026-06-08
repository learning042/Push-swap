/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:29:12 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/16 16:11:46 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static char	ft_test(unsigned int i, char c)
{
	return (c + i);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*s2;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	s2 = malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = f(i, s[i]);
		++i;
	}
	s2[i] = '\0';
	return (s2);
}
/*
#include <stdio.h>
int	main(void)
{
	char const 	*s1 = "12345";
	char		*s2 = ft_strmapi(s1, ft_test);
	printf("%s\n", s1);
	printf("%s\n", s2);
	return (0);
}
*/
