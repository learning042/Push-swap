/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:46:48 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/06/09 17:04:26 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *s)
{
	size_t	mistakes;
	size_t	total_pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < s->curr_size)
	{
		j = i + 1;
		while (j < s->curr_size)
		{
			++total_pairs;
			if (access_stack(s, i) > access_stack(s, j))
				++mistakes;
			++j;
		}
		++i;
	}
	return ((float) mistakes / total_pairs);
}

void	init_bench(t_stack *s, t_bench *bench)
{
	float	disorder;

	disorder = compute_disorder(s);
	bench->disorder = disorder;
	
	if (disorder < 0.2)
		return ((void) (bench->strategy = Simple));
	if (0.2 <= disorder && disorder < 0.5)
		return ((void) (bench->strategy = Medium));
	if (0.5 <= disorder)
		return ((void) (bench->strategy = Complex));
}
