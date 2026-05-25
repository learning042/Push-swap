/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:36:03 by jlandeir          #+#    #+#             */
/*   Updated: 2026/05/12 17:47:05 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	s->array[rem(s->top + s->curr_size, s->max_size)] = s->array[s->top];
	s->top = rem(s->top + 1, s->max_size);
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
