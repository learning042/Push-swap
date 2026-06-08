/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:15:07 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/08 15:39:30 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_min(t_stack *s)
{
	size_t	i;
	size_t	temp_min;

	if (s->curr_size == 0)
		return (0);
	i = 1;
	temp_min = 0;
	while (i < s->curr_size)
	{
		if (access_stack(s, i) < access_stack(s, temp_min))
			temp_min = i;
		i++;
	}
	return (temp_min);
}

static void	push_min(t_stack *a, t_stack *b, t_move_count *move_count)
{
	size_t	min;
	size_t	i;

	min = find_min(a);
	if (min < a->curr_size / 2)
	{
		i = 0;
		while (i < min)
		{
			rotate_a(a, move_count);
			i++;
		}
	}
	else
	{
		i = a->curr_size - 1;
		while (i >= min)
		{
			rev_rotate_a(a, move_count);
			i--;
		}
	}
	push_b(a, b, move_count);
	return ;
}

void	insertion_sort(t_stack *a, t_stack *b, t_move_count *move_count)
{
	while (a->curr_size != 1)
		push_min(a, b, move_count);
	while (b->curr_size != 0)
		push_a(a, b, move_count);
	return ;
}
