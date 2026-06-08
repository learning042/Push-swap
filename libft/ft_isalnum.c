/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 16:38:20 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/13 11:54:09 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((ft_isalpha(c) || ft_isdigit(c)));
}
/*#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%i\n", isalnum(239));
	//printf("%i\n", ft_isalnum(239));
	printf("%i\n", isalnum('a'));
	//printf("%i\n", ft_isalnum('a'));
	printf("%i\n", isalnum('1'));
	//printf("%i\n", ft_isalnum('1'));
	printf("%i\n", isalnum('9'));
	//printf("%i\n", ft_isalnum('9'));
	return (0);
}*/
