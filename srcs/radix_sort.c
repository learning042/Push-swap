/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:16:46 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/11 13:39:52 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// get the number of bits of a number
int	num_bits(int num)
{
	int	bits;

	bits = 0;
	num--;
	while (num)
	{
		num >>= 1;
		++bits;
	}
	return (bits);
}

// build a ranked stack
void	rank_stack(t_stack *s)
{
	int		*rank_array;
	int		rank;
	size_t	i;
	size_t	j;

	rank_array = malloc(sizeof(int) * s->curr_size);
	if (!rank_array)
		return ;
	i = 0;
	while (i < s->curr_size)
	{
		rank = 0;
		j = 0;
		while (j < s->curr_size)
		{
			if (access_stack(s, j) < access_stack(s, i))
				rank++;
			j++;
		}
		rank_array[i] = rank;
		i++;
	}
	init_stack(s, rank_array);
	free(rank_array);
	return ;
}

void	radix_sort(t_stack *a, t_stack *b, t_move_count *move_count)
{
	int	i;
	int	j;
	int	size;
	int	bits;

	rank_stack(a);
	size = a->curr_size;
	bits = num_bits(size);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if ((access_stack(a, 0) >> i) & 1)
				rotate_a(a, move_count);
			else
				push_b(a, b, move_count);
			++j;
		}
		while (b->curr_size)
			push_a(a, b, move_count);
		++i;
	}
}
