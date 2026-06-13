/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:46:04 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/13 15:21:09 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack *s)
{
	int	new_top;
	int	new_top_value;

	new_top = mod(s->top - 1, s->max_size);
	new_top_value = access_stack(s, s->curr_size - 1);
	s->top = new_top;
	edit_stack(s, 0, new_top_value);
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
