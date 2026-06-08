/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_numptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:03:27 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/27 17:35:17 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

void	ft_putnbr_base(unsigned long n, char *base, size_t lbase, int *count)
{
	if (n < lbase)
	{
		ft_putchar(base[n], count);
		return ;
	}
	ft_putnbr_base(n / lbase, base, lbase, count);
	ft_putnbr_base(n % lbase, base, lbase, count);
}

void	ft_putsign(long n, char *base, int *count)
{
	if (n < 0)
	{
		ft_putchar('-', count);
		n *= -1;
	}
	ft_putnbr_base(n, base, ft_strlen(base), count);
}

void	ft_putuns(unsigned long n, char *base, int *count)
{
	ft_putnbr_base(n, base, ft_strlen(base), count);
}

void	ft_putptr(unsigned long n, int *count)
{
	if (n == 0)
		return (ft_putstr("(nil)", count));
	ft_putstr("0x", count);
	ft_putuns(n, HEXBASELOW, count);
}
