/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 17:05:46 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/13 11:56:24 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%i\n", isalpha('a'));
	printf("%i\n", ft_isalpha('a'));
	printf("%i\n", isalpha('M'));
	printf("%i\n", ft_isalpha('M'));
	printf("%i\n", isalpha('0'));
	printf("%i\n", ft_isalpha('0'));
	return (0);
}
*/
