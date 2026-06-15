/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:18:34 by jlandeir          #+#    #+#             */
/*   Updated: 2026/04/28 16:04:59 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	start = 0;
	end = len - 1;
	while (start < len && ft_char_in_set(s1[start], set))
		start++;
	if (start == len)
		return (ft_strdup(""));
	while (ft_char_in_set(s1[end], set))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
