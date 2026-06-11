/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:58:26 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/11 13:41:17 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_sqrt(size_t num)
{
	size_t	i;

	i = 0;
	while (i * i <= num)
	{
		if (i * i == num)
			return (i);
		++i;
	}
	return (i);
}

static void	push_bucket(t_stack *a, t_stack *b, size_t bucket, t_move_count *mv)
{
	size_t	init_size_a;
	size_t	j;
	size_t	n;
	size_t	bucket_size;

	bucket_size = 2 * ft_sqrt(a->max_size);
	init_size_a = a->curr_size;
	j = 0;
	n = a->max_size;
	while (j < init_size_a)
	{
		if (access_stack(a, 0) / bucket_size == bucket)
			push_b(a, b, mv);
		else
			rotate_a(a, mv);
		++j;
	}
}

void	bucket_sort(t_stack *a, t_stack *b, t_move_count *move_count)
{
	size_t	bucket_size;
	size_t	bucket;

	rank_stack(a);
	bucket_size = 2 * ft_sqrt(a->max_size);
	bucket = 0;
	while (bucket <= a->max_size / bucket_size)
	{
		push_bucket(a, b, bucket, move_count);
		bucket++;
	}
	rev_insertion_sort(a, b, move_count);
}
