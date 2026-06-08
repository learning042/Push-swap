/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:52:21 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/08 16:13:43 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mod(int a, int b)
{
	return ((a % b + b) % b);
}

t_stack	*create_stack(int *nbrs, size_t nbr_count, size_t size)
{
	t_stack	*new;
	int		*new_array;

	new_array = malloc(sizeof(int) * size);
	if (new_array == NULL)
		return (NULL);
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->array = new_array;
	new->top = 0;
	new->curr_size = nbr_count;
	new->max_size = size;
	init_stack(new, nbrs);
	return (new);
}

void	init_stack(t_stack *s, int *arr)
{
	size_t	i;

	i = 0;
	while (i < s->curr_size)
	{
		edit_stack(s, i, arr[i]);
		i++;
	}
	return ;
}

int	access_stack(t_stack *s, size_t i)
{
	if (s->top + i >= s->max_size)
		return (s->array[s->top - (s->max_size - i)]);
	return (s->array[s->top + i]);
}

void	edit_stack(t_stack *s, size_t i, int n)
{
	if (s->top + i >= s-> max_size)
	{
		s->array[s->top - (s->max_size - i)] = n;
		return ;
	}
	s->array[s->top + i] = n;
	return ;
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

void	print_move_count(t_move_count *m)
{
	size_t	total;
	int		i;

	total = 0;
	i = 0;
	printf("total_ops: %zu\n", m->total);
	printf("sa: %zu, sb: %zu, ss: %zu, pa: %zu, pb: %zu\n",
		m->sa, m->sb, m->ss, m->pa, m->pb);
	printf("ra: %zu, rb: %zu, rr: %zu, rra: %zu, rrb: %zu, rrr: %zu\n",
		m->ra, m->rb, m->rr, m->rra, m->rrb, m->rrr);
	return ;
}
