/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:12:06 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/15 13:42:42 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static void	ft_display_specifier(int fd, char spec, va_list args, int *count)
{
	if (spec == 'c')
		*count += ft_putchar(fd, (unsigned char) va_arg(args, int));
	else if (spec == 's')
		*count += ft_putstr(fd, va_arg(args, char *));
	else if (spec == 'p')
		*count += ft_putptr(fd, va_arg(args, void *));
	else if (spec == 'd' || spec == 'i')
		*count += ft_putnbr(fd, va_arg(args, int));
	else if (spec == 'u')
		*count += ft_put_unsignedint(fd, va_arg(args, unsigned int));
	else if (spec == 'x')
		*count += ft_put_hex_lower(fd, va_arg(args, unsigned int));
	else if (spec == 'X')
		*count += ft_put_hex_upper(fd, va_arg(args, unsigned int));
	else if (spec == '%')
		*count += ft_putchar(fd, '%');
	else
		*count = -1;
	return ;
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(fd, *format);
			format++;
			count++;
			continue ;
		}
		format++;
		ft_display_specifier(fd, *format, args, &count);
		if (count == -1)
			return (-1);
		format++;
	}
	va_end(args);
	return (count);
}
