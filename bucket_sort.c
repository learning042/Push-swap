/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:58:26 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/02 16:02:21 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ranks x 
//ft_sqrt
//
int	ft_sqrt(int num)
{
	int	i;

	i = 0;
	while (i * i <= num)
	{
		if(i * i == num)
			return (i);
		++i;
	}
//	if (i * i - num > num - (i - 1) * (i - 1))
//		--i;
	return (i - 1);
}
//push_bucket

void	push_bucket(t_stack *a, t_stack *b, size_t bucket, int bucket_size)
{
	size_t	curr_size;
	size_t	j;
	size_t	n;

	init_size_a = a->curr_size;
	j = 0;
	n = a->max_size;
	while (j < init_size_a)
	{
		if (access_stack(a, 0) / bucket_size ==  bucket)
			push_b(a, b);
		else
			rotate_a(a);
		++j;
	}
}
//bucket_sort push_bucket pop everything from b to a	
int	main(void)
{
	printf("%i\n", ft_sqrt(10));
	printf("%i\n", ft_sqrt(50));
	printf("%i\n", ft_sqrt(400));
}
