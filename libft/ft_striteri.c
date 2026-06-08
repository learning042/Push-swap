/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:23:14 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/16 16:48:44 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	ft_test(unsigned int i, char *c)
{
	*c += i;
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		++i;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s = malloc(6);
	int	i = 0;
	for (i = 0; i < 5; i++)
	{
		s[i] = i + '0';
	}
	printf("%s\n", s);
	ft_striteri(s, ft_test);
	printf("%s\n", s);
}
*/
