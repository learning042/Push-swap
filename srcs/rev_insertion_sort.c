/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_insertion_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:17:06 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/08 15:40:48 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_max(t_stack *s)
{
	size_t	i;
	size_t	temp_max;

	if (s->curr_size == 0)
		return (0);
	i = 1;
	temp_max = 0;
	while (i < s->curr_size)
	{
		if (access_stack(s, i) > access_stack(s, temp_max))
			temp_max = i;
		i++;
	}
	return (temp_max);
}

static void	push_max(t_stack *a, t_stack *b, t_move_count *move_count)
{
	size_t	max;
	size_t	i;

	max = find_max(b);
	if (max < b->curr_size / 2)
	{
		i = 0;
		while (i < max)
		{
			rotate_b(b, move_count);
			i++;
		}
	}
	else
	{
		i = b->curr_size - 1;
		while (i >= max)
		{
			rev_rotate_b(b, move_count);
			i--;
		}
	}
	push_a(a, b, move_count);
	return ;
}

void	rev_insertion_sort(t_stack *a, t_stack *b, t_move_count *move_count)
{
	while (b->curr_size != 1)
		push_max(a, b, move_count);
	push_a(a, b, move_count);
	return ;
}
