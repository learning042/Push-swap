/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:46:04 by jlandeir          #+#    #+#             */
/*   Updated: 2026/05/28 12:22:23 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack *s)
{
	s->array[mod(s->top - 1, s->max_size)] = s->array[mod(s->top + s-> curr_size - 1, s->max_size)];
	s->top = mod(s->top - 1, s->max_size);
	return ;
}

void	rev_rotate_a(t_stack *a)
{
	rev_rotate(a);
	printf("rra\n");
	return ;
}

void	rev_rotate_b(t_stack *b)
{
	rev_rotate(b);
	printf("rrb\n");
	return ;
}

void	rev_rotate_both(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
	printf("rrr\n");
	return ;
}
