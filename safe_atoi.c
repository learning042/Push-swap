/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:45:49 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/15 12:46:08 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	safe_add(int a, int b, int *res)
{
	if (a > 0 && b > 0 && (a > INT_MAX - b))
		return (-1);
	if (a < 0 && b < 0 && (a < INT_MIN - b))
		return (-1);
	*res = a + b;
	return (0);
}

static int	safe_mult(int a, int b, int *res)
{
	if (a == 0 || b == 0)
	{
		*res = 0;
		return (0);
	}
	if (((a > 0 && b > 0) || (a < 0 && b < 0)) && (a <= INT_MAX / b))
	{
		*res = a * b;
		return (0);
	}
	if (((a > 0 && b < 0) || (a < 0 && b > 0)) && (a <= INT_MIN / b))
	{
		*res = a * b;
		return (0);
	}
	return (-1);
}

int	safe_atoi(char *str, int *val)
{
	size_t	i;
	int		sign;
	int		res;

	if (str[0] == '\0')
		return (-1);
	if ((str[0] == '+' || str[0] == '-') && (str[1] < '0' || str[1] > '9'))
		return (-1);
	res = 0;
	i = (str[0] == '+') || (str[0] == '-');
	sign = 1 - 2 * (str[0]);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if (safe_mult(10, res, &res) == -1)
			return (-1);
		if (safe_add(res, sign * (str[i] - '0'), &res) == -1)
			return (-1);
		i++;
	}
	*val = res;
	return (0);
}
