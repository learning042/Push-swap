/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:52:21 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/15 13:43:32 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mod(int a, int b)
{
	return ((a % b + b) % b);
}

void	print_move_count(t_move_count *m)
{
	ft_fprintf(2, "[bench] total_ops: %d\n", m->total);
	ft_fprintf(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		m->sa, m->sb, m->ss, m->pa, m->pb, 2);
	ft_fprintf(2, "[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		m->ra, m->rb, m->rr, m->rra, m->rrb, m->rrr);
	return ;
}

int	is_sorted(t_stack *a, t_stack *b)
{
	size_t	i;

	i = 0;
	while (i + 1 < a->curr_size)
	{
		if (access_stack(a, i) > access_stack(a, i + 1))
			return (0);
		i++;
	}
	if (b->curr_size != 0)
		return (0);
	return (1);
}
