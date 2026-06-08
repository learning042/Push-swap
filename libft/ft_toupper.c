/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 00:52:33 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/17 12:56:30 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= ' ';
	return (c);
}
/*#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_toupper(150));
	printf("%c\n", ft_toupper('c'));
	return (0);
}
*/
