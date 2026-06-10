/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:52:21 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/09 17:34:39 by jlandeir         ###   ########.fr       */
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
	ft_printf("[bench] total_ops: %d\n", m->total);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n",
		m->sa, m->sb, m->ss, m->pa, m->pb);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
		m->ra, m->rb, m->rr, m->rra, m->rrb, m->rrr);
	return ;
}
