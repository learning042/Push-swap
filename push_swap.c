/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:48:57 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/15 13:58:26 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_move_count(t_move_count *moves)
{
	const t_move_count	zero = {0};

	*moves = zero;
}

/*
static void	print_stack(t_stack *s)
{
	size_t	i;

	i = 0;
	while (i < s->curr_size)
	{
		ft_fprintf(2, "%d\n", access_stack(s, i));
		i++;
	}
	return ;
}
*/

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	t_move_count	move_count;
	t_bench			bench;
	int				first_nbr;

	if (argc == 1)
		return (0);
	init_move_count(&move_count);
	if (parser(argc, argv, &bench, &first_nbr) == -1)
		return (-1);
	if (build_stacks(argc - first_nbr, argv + first_nbr, &a, &b) == -1)
		return (-1);
	init_bench_disorder(a, &bench);
	apply_strat(a, b, &move_count, bench);
	if (bench.has_bench)
		print_bench(&bench, &move_count);
	free_stack(a);
	free_stack(b);
	return (0);
}
