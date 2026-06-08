/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:46:48 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/06/08 14:54:00 by tpinto-v         ###   ########.fr       */
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
	while(i < s->curr_size)
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
