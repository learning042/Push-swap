/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:05:32 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/20 19:09:32 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a, t_move_count *move)
{
	const int	first = access_stack(a, 0);
	const int	second = access_stack(a, 1);
	const int	third = access_stack(a, 2);

	if (first < third && third < second)
	{
		rev_rotate_a(a, move);
		swap_a(a, move);
	}
	if (second < first && first < third)
		swap_a(a, move);
	if (third < first && first < second)
		rev_rotate_a(a, move);
	if (second < third && third < first)
		rotate_a(a, move);
	if (third < second && second < first)
	{
		rotate_a(a, move);
		swap_a(a, move);
	}
	return ;
}
