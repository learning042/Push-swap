/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:46:04 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/08 15:32:35 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack *s)
{
	s->array[mod(s->top - 1, s->max_size)] = s->array[mod(s->top + s-> curr_size - 1, s->max_size)];
	s->top = mod(s->top - 1, s->max_size);
	return ;
}

void	rev_rotate_a(t_stack *a, t_move_count *m)
{
	rev_rotate(a);
	m->rra++;
	m->total++;
	printf("rra\n");
	return ;
}

void	rev_rotate_b(t_stack *b, t_move_count *m)
{
	rev_rotate(b);
	m->rrb++;
	m->total++;
	printf("rrb\n");
	return ;
}

void	rev_rotate_both(t_stack *a, t_stack *b, t_move_count *m)
{
	rev_rotate(a);
	rev_rotate(b);
	m->rrr++;
	m->total++;
	printf("rrr\n");
	return ;
}
