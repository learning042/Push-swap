/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:36:03 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/08 15:50:00 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	s->array[mod(s->top + s->curr_size, s->max_size)] = s->array[s->top];
	s->top = mod(s->top + 1, s->max_size);
	return ;
}

void	rotate_a(t_stack *a, t_move_count *m)
{
	rotate(a);
	m->ra++;
	m->total++;
	printf("ra\n");
	return ;
}

void	rotate_b(t_stack *b, t_move_count *m)
{
	rotate(b);
	m->rb++;
	m->total++;
	printf("rb\n");
	return ;
}

void	rotate_both(t_stack *a, t_stack *b, t_move_count *m)
{
	rotate(a);
	rotate(b);
	m->rr++;
	m->total++;
	printf("rr\n");
	return ;
}
