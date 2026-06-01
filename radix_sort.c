/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:16:46 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/01 14:53:50 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rank_stack(t_stack *s)
{
	int	*index_array;
	int	rank;
	size_t	i;
	size_t	j;
	t_stack	*rank_stack;

	rank_array = malloc(sizeof(int) * s->curr_size);
	if (rank_array == NULL)
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
	rank_stack = create_stack(rank_array, s->curr_size, s->max_size);
	free_stack(s);
	free(rank_array);
	return (rank_stack);
}

void	radix_sort(t_stack *a, t_stack *b, size_t *move_count)
{

	t_stack	*rank_stack;

	rank_stack = rank_stack(a);




