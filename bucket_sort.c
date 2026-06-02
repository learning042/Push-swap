/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:58:26 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/02 18:09:22 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ranks x 
//ft_sqrt
//
static size_t	ft_sqrt(size_t num)
{
	size_t	i;

	i = 0;
	while (i * i <= num)
	{
		if(i * i == num)
			return (i);
		++i;
	}
//	if (i * i - num > num - (i - 1) * (i - 1))
//		--i;
	return (i);
}
//push_bucket

static void	push_bucket(t_stack *a, t_stack *b, size_t bucket, size_t bucket_size, size_t *move_count)
{
	size_t	init_size_a;
	size_t	j;
	size_t	n;

	init_size_a = a->curr_size;
	j = 0;
	n = a->max_size;
	while (j < init_size_a)
	{
		if (access_stack(a, 0) / bucket_size == bucket)
		{
			push_b(a, b);
			move_count[PB]++;
		}
		else
		{
			rotate_a(a);
			move_count[RA]++;
		}
		++j;
	}
}

void	bucket_sort(t_stack *a, t_stack *b, size_t *move_count)
{
	size_t	bucket_size;
	size_t	bucket;
	
	rank_stack(a);
	bucket_size = ft_sqrt(a->max_size);
	bucket = 0;
	while (bucket <= a->max_size / bucket_size)
	{
		push_bucket(a, b, bucket, bucket_size, move_count);
		bucket++;
	}
	rev_insertion_sort(a, b, move_count);
}
//bucket_sort push_bucket pop everything from b to a	
/*int	main(void)
{
	printf("%i\n", ft_sqrt(10));
	printf("%i\n", ft_sqrt(50));
	printf("%i\n", ft_sqrt(400));
}
*/
