/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:11:49 by jlandeir          #+#    #+#             */
/*   Updated: 2026/05/23 16:43:45 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	size_t	i;

	i = 0;
	if (s->curr_size < 2)
		return (1);
	while (i + 1 < s->curr_size)
	{
		if (access_stack(s, i) > access_stack(s, i + 1))
			return (0);
		i++;
	}
	return (1);
}




