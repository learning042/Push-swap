/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:45:08 by jlandeir          #+#    #+#             */
/*   Updated: 2026/05/28 12:07:04 by tpinto-v         ###   ########.fr       */
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

void	push_a(t_stack *a, t_stack *b)
{
	push(b, a);
	printf("pa\n");
	return ;
}

void	push_b(t_stack *a, t_stack *b)
{
	push(a, b);
	printf("pb\n");
	return ;
}
