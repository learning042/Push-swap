/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:48:51 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/15 12:49:00 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_stack(t_stack *s)
{
	free(s->array);
	free(s);
}
