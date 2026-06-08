/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_charstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:59:29 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/27 15:02:31 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr(char *s, int *count)
{
	int	len;

	if (s == NULL)
	{
		len = ft_strlen("(null)");
		write(1, "(null)", len);
		*count += len;
		return ;
	}
	len = ft_strlen(s);
	write(1, s, len);
	*count += len;
}
