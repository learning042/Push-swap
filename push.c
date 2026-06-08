/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:45:08 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/08 15:56:23 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *a, t_stack *b)
{
	if (a->curr_size == 0)
		return ;
	b->array[mod(b->top - 1, b->max_size)] = a->array[a->top];
	a->curr_size--;
	b->curr_size++;
	a->top = mod(a->top + 1, a->max_size);
	b->top = mod(b->top - 1, b->max_size);
	return ;
}

void	push_a(t_stack *a, t_stack *b, t_move_count *m)
{
	push(b, a);
	m->pa++;
	m->total++;
	printf("pa\n");
	return ;
}

void	push_b(t_stack *a, t_stack *b, t_move_count *m)
{
	push(a, b);
	m->pb++;
	m->total++;
	printf("pb\n");
	return ;
}
