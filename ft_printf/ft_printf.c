/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:17:45 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/27 16:30:25 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_display_formatted(char specifier, va_list displayed, int *count)
{
	if (specifier == 'c')
		ft_putchar((char) va_arg(displayed, int), count);
	else if (specifier == 's')
		ft_putstr(va_arg(displayed, char *), count);
	else if (specifier == 'p')
		ft_putptr((unsigned long) va_arg(displayed, void *), HEXBASELOW, count);
	else if (specifier == 'i' || specifier == 'd')
		ft_putsign(va_arg(displayed, int), DECBASE, count);
	else if (specifier == 'u')
		ft_putuns(va_arg(displayed, unsigned int), DECBASE, count);
	else if (specifier == 'x')
		ft_putuns(va_arg(displayed, unsigned int), HEXBASELOW, count);
	else if (specifier == 'X')
		ft_putuns(va_arg(displayed, unsigned int), HEXBASEUPP, count);
	else if (specifier == '%')
		ft_putchar('%', count);
	else
		*count = -1;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		*count;

	if (s == NULL)
		return (-1);
	va_start(args, s);
	i = 0;
	count = &i;
	while (*s)
	{
		if (*s == '%')
		{
			ft_display_formatted(s[1], args, count);
			if (*count == -1)
				break ;
			s += 2;
			continue ;
		}
		ft_putchar(*s, count);
		++s;
	}
	va_end(args);
	return (*count);
}
