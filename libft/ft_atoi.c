/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:01:27 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/19 21:17:22 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	number;

	number = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	while (ft_isdigit(*nptr) != 0)
	{
		number = number * 10 + sign * (*(nptr++) - '0');
	}
	return (number);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_atoi("-2147483648"));
	printf("%i\n", ft_atoi("212121abcd"));
	printf("%i\n", ft_atoi(" -21rjedkfj"));
	printf("%i\n", ft_atoi("-2147483647"));
	printf("%i\n", ft_atoi("  -2"));
	printf("%i\n", ft_atoi("-+4"));
	printf("%i\n", ft_atoi("-4886"));
	return (0);
}
*/
