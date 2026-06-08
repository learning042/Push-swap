/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 16:51:35 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/16 18:03:40 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%i\n", isdigit('0'));
	printf("%i\n", ft_isdigit('0'));
	printf("%i\n", isdigit('a'));
	printf("%i\n", ft_isdigit('a'));
	printf("%i\n", isdigit(150));
	printf("%i\n", ft_isdigit(150));
	return (0);
}
*/
