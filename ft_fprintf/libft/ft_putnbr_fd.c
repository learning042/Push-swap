/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:34:59 by jlandeir          #+#    #+#             */
/*   Updated: 2026/04/21 17:00:29 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_signless_putnbr_fd(int n, int fd)
{
	int		sign;
	char	c;

	sign = 2 * (n >= 0) - 1;
	if (-10 < n && n < 10)
	{
		c = '0' + sign * n;
		ft_putchar_fd(c, fd);
		return ;
	}
	else
	{
		ft_signless_putnbr_fd(n / 10, fd);
		ft_signless_putnbr_fd(n % 10, fd);
		return ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_signless_putnbr_fd(n, fd);
	return ;
}
