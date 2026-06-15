/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:11:49 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/15 11:44:37 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

static int	apply_moves(t_stack *a, t_stack *b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		return (swap_top(a), 0);
	if (!ft_strcmp(move, "sb\n"))
		return (swap_top(b), 0);
	if (!ft_strcmp(move, "ss\n"))
		return (swap_top(a), swap_top(b), 0);
	if (!ft_strcmp(move, "pa\n"))
		return (push(b, a), 0);
	if (!ft_strcmp(move, "pb\n"))
		return (push(a, b), 0);
	if (!ft_strcmp(move, "ra\n"))
		return (rotate(a), 0);
	if (!ft_strcmp(move, "rb\n"))
		return (rotate(b), 0);
	if (!ft_strcmp(move, "rr\n"))
		return (rotate(a), rotate(b), 0);
	if (!ft_strcmp(move, "rra\n"))
		return (rev_rotate(a), 0);
	if (!ft_strcmp(move, "rrb\n"))
		return (rev_rotate(b), 0);
	if (!ft_strcmp(move, "rrr\n"))
		return (rev_rotate(a), rev_rotate(b), 0);
	return (ft_putstr_fd("Error\n", 2), -1);
}

int	main(int argc, char **argv)
{
	size_t	nbr_count;
	t_stack	*a;
	t_stack	*b;
	char	*moves;

	nbr_count = argc - 1;
	if (argc == 1)
		return (0);
	if (build_stacks(nbr_count, argv + 1, &a, &b) == -1)
		return (-1);
	moves = get_next_line(0);
	while (moves != NULL)
	{
		if (apply_moves(a, b, moves) == -1)
			return (-1);
		free(moves);
		moves = get_next_line(0);
	}
	free(moves);
	if (is_sorted(a, b))
		return (free_stack(a), free_stack(b), ft_putstr_fd("OK\n", 1), 0);
	return (free_stack(a), free_stack(b), ft_putstr_fd("KO\n", 1), 0);
}
