/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:45:08 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/15 14:25:18 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *a, t_stack *b)
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
	ft_fprintf(1, "pa\n");
	return ;
}

void	push_b(t_stack *a, t_stack *b, t_move_count *m)
{
	push(a, b);
	m->pb++;
	m->total++;
	ft_fprintf(1, "pb\n");
	return ;
}
