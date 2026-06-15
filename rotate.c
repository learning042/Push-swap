/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:36:03 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/15 14:25:55 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *s)
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
	ft_fprintf(1, "ra\n");
	return ;
}

void	rotate_b(t_stack *b, t_move_count *m)
{
	rotate(b);
	m->rb++;
	m->total++;
	ft_fprintf(1, "rb\n");
	return ;
}

void	rotate_both(t_stack *a, t_stack *b, t_move_count *m)
{
	rotate(a);
	rotate(b);
	m->rr++;
	m->total++;
	ft_fprintf(1, "rr\n");
	return ;
}
