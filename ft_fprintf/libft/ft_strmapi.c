/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:52:43 by jlandeir          #+#    #+#             */
/*   Updated: 2026/04/21 15:57:26 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*f_s;

	len = ft_strlen(s);
	f_s = malloc((len + 1) * sizeof(char));
	if (f_s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		f_s[i] = f(i, s[i]);
		i++;
	}
	f_s[len] = '\0';
	return (f_s);
}
