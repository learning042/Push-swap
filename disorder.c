/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:46:48 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/06/10 16:11:10 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rational	compute_disorder(t_stack *s)
{
	size_t	mistakes;
//	size_t	total_pairs;
	size_t	i;
	size_t	j;
	t_rational	disorder;

	mistakes = 0;
	i = 0;
	while (i < s->curr_size)
	{
		j = i + 1;
		while (j < s->curr_size)
		{
			if (access_stack(s, i) > access_stack(s, j))
				++mistakes;
			++j;
		}
		++i;
	}
	disorder.num = mistakes;
	disorder.den = (s->curr_size * (s->curr_size + 1)) / 2;
	return (disorder);
}

