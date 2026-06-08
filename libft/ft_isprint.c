/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:50:36 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/13 11:58:28 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%i\n", isprint(65));
	printf("%i\n", ft_isprint(65));
	printf("%i\n", isprint(126));
	printf("%i\n", ft_isprint(126));
}
*/
