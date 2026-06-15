/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:46:26 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/15 13:42:01 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	ft_putnbr_base(int fd, unsigned long long n, const char *base,
const unsigned int base_len)
{
	int	len;

	if (n < base_len)
	{
		write(fd, &base[n], 1);
		return (1);
	}
	len = ft_putnbr_base(fd, n / base_len, base, base_len);
	len += ft_putnbr_base(fd, n % base_len, base, base_len);
	return (len);
}

int	ft_putptr(int fd, void *ptr)
{
	const char			*base = "0123456789abcdef";
	const unsigned int	base_len = 16;

	if (ptr == NULL)
		return (ft_putstr(fd, "(nil)"));
	write(fd, "0x", 2);
	return (2 + ft_putnbr_base(fd, (unsigned long long) ptr, base, base_len));
}

int	ft_put_unsignedint(int fd, unsigned int n)
{
	const char			*base = "0123456789";
	const unsigned int	base_len = 10;

	return (ft_putnbr_base(fd, (unsigned long long) n, base, base_len));
}

int	ft_put_hex_lower(int fd, unsigned int n)
{
	const char			*base = "0123456789abcdef";
	const unsigned int	base_len = 16;

	return (ft_putnbr_base(fd, (unsigned long long) n, base, base_len));
}

int	ft_put_hex_upper(int fd, unsigned int n)
{
	const char			*base = "0123456789ABCDEF";
	const unsigned int	base_len = 16;

	return (ft_putnbr_base(fd, (unsigned long long) n, base, base_len));
}
