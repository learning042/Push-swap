/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:20:15 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/08 15:49:44 by tpinto-v         ###   ########.fr       */
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

static void	swap_top(t_stack *s)
{
	size_t	s_max_size;
	size_t	s_top;
	int		*s_array;

	if (s->curr_size <= 1)
		return ;
	s_max_size = s->max_size;
	s_top = s->top;
	s_array = s->array;
	swap_ints(&s_array[access_stack(s, 0)], &s_array[access_stack(s, 1)]);
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

