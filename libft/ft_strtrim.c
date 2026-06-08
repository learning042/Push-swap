/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:09:43 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/17 12:29:39 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

/*
  The function cut/trim the values from the left and then from the right of it
  which are in the *set* string and then dynamically allocates memory to store 
  a trimmed copy of the string. The return value is the pointer to the first char
  of in the trimmed string and NULL if the allocation fails.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	right;
	size_t	left;

	if (s1 == NULL || set == NULL)
		return (NULL);
	right = ft_strlen(s1) - 1;
	left = 0;
	while (in_set(s1[left], set))
		++left;
	if (left == right + 1)
		return (ft_strdup(""));
	while (in_set(s1[right], set))
		--right;
	return (ft_substr(s1, left, right - left + 1));
}
/*
#include <stdio.h>
int	main(void)
{
	char const	*s = "hello";
	char	*s_trimmed = ft_strtrim(s, "lo");
	printf("%s\n", s_trimmed);
	return (0);
}
*/
