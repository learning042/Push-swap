/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:36:03 by jlandeir          #+#    #+#             */
/*   Updated: 2026/05/28 12:09:12 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	s->array[mod(s->top + s->curr_size, s->max_size)] = s->array[s->top];
	s->top = mod(s->top + 1, s->max_size);
	return ;
}

void	rotate_a(t_stack *a)
{
	rotate(a);
	printf("ra\n");
	return ;
}

void	rotate_b(t_stack *b)
{
	rotate(b);
	printf("rb\n");
	return ;
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
	return ;
}
