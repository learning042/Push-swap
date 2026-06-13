/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:20:15 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/13 18:05:15 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_ints(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	swap_top(t_stack *s)
{
	size_t	max_size;
	size_t	s_top;
	int		*s_array;

	if (s->curr_size <= 1)
		return ;
	max_size = s->max_size;
	s_top = s->top;
	s_array = s->array;
	swap_ints(&s_array[s_top], &s_array[mod(s_top + 1, max_size)]);
	return ;
}

void	swap_a(t_stack *a, t_move_count *m)
{
	swap_top(a);
	m->sa++;
	m->total++;
	printf("sa\n");
	return ;
}

void	swap_b(t_stack *b, t_move_count *m)
{
	swap_top(b);
	m->sb++;
	m->total++;
	printf("sb\n");
	return ;
}

void	swap_both(t_stack *a, t_stack *b, t_move_count *m)
{
	swap_top(a);
	swap_top(b);
	m->ss++;
	m->total++;
	printf("ss\n");
	return ;
}
