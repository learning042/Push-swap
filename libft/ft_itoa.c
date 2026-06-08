/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:01:13 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/19 21:57:49 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_count_digits(long num)
{
	if (num < 0)
		num *= -1;
	if (num >= 0 && num <= 9)
		return (1);
	return (1 + ft_count_digits(num / 10));
}

static char	*ft_itoa_long(long n)
{
	char		*num;
	long		mem_alloc;
	long		isneg;

	isneg = (n < 0);
	mem_alloc = ft_count_digits(n) + 1 + isneg;
	num = malloc(mem_alloc);
	if (num == NULL)
		return (NULL);
	num[mem_alloc - 1] = '\0';
	if (n == 0)
		num[0] = '0';
	if (n < 0)
		n *= -1;
	while (mem_alloc-- && n != 0)
	{
		num[mem_alloc - 1] = n % 10 + '0';
		n /= 10;
	}
	if (isneg)
		num[0] = '-';
	return (num);
}

char	*ft_itoa(int n)
{
	return (ft_itoa_long((long) n));
}
/*
#include <stdio.h>
int	main(void)
{
	int		n = 2147483648;
	int		n1 = 42;
	char	*num = ft_itoa(n);
	printf("%s\n", num);
	free(num);
	
	char	*num1 = ft_itoa(n1);
	printf("%s\n", num1);
	free(num1);
	return (0);
}
*/
