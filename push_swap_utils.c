/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:52:21 by jlandeir          #+#    #+#             */
/*   Updated: 2026/05/23 16:22:04 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rem(int a, int b)
{
	return ((a % b + b) % b);
}

t_stack	*create_stack(int *nbrs, size_t nbr_count, size_t size)
{
	t_stack	*new;
	int		*new_array;
	size_t	i;

	new_array = malloc(sizeof(int) * size);
	if (new_array == NULL)
		return (NULL);
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < nbr_count)
	{
		new_array[i] = nbrs[i];
		i++;
	}
	new->array = new_array;
	new->top = 0;
	new->curr_size = nbr_count;
	new->max_size = size;
	return (new);
}

int	access_stack(t_stack *s, size_t i)
{
	if (s->top + i >= s->max_size)
		return (s->array[s->top - (s->max_size - i)]);
	return (s->array[s->top + i]);
}

void	print_stack(t_stack *s)
{
	size_t	i;

	i = 0;
	while (i < s->curr_size)
	{
		printf("%d\n", access_stack(s, i));
		i++;
	}
	return ;
}

void	free_stack(t_stack *s)
{
	free(s->array);
	free(s);
}

void	print_move_count(size_t *mv)
{
	size_t	total;
	int		i;

	total = 0;
	i = 0;
	while (i < 11)
	{
		total += mv[i];
		i++;
	}
	printf("total_ops: %zu\n", total);
	printf("sa: %zu, sb: %zu, ss: %zu, pa: %zu, pb: %zu\n",
		mv[0], mv[1], mv[2], mv[3], mv[4]);
	printf("ra: %zu, rb: %zu, rr: %zu, rra: %zu, rrb: %zu, rrr: %zu\n",
		mv[5], mv[6], mv[7], mv[8], mv[9], mv[10]);
	return ;
}
