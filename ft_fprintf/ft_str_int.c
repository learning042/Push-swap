/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:06:08 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/15 13:42:16 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_putchar(int fd, unsigned char c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr(int fd, char *s)
{
	int	len;

	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}

static int	ft_signless_putnbr(int fd, int n)
{
	int		sign;
	char	c;
	int		len;

	sign = 2 * (n >= 0) - 1;
	len = 0;
	if (-10 < n && n < 10)
	{
		c = '0' + sign * n;
		return (ft_putchar(fd, c));
	}
	else
	{
		len = ft_signless_putnbr(fd, n / 10);
		ft_signless_putnbr(fd, n % 10);
		return (len + 1);
	}
}

int	ft_putnbr(int fd, int n)
{
	if (n < 0)
	{
		ft_putchar(fd, '-');
		return (1 + ft_signless_putnbr(fd, n));
	}
	return (ft_signless_putnbr(fd, n));
}
