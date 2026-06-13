/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:48:57 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/13 19:41:47 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_move_count(t_move_count *moves)
{
	const t_move_count	zero = {0};

	*moves = zero;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_move_count	move_count;
	t_bench	bench;
	int	first_nbr;
	int	test;
	
	if (argc == 1)
		return (0);
	init_move_count(&move_count);
	if (parser(argc, argv, &bench, &first_nbr) == -1)
		return (-1);
	if (build_stacks(argc - first_nbr, argv + first_nbr, &a, &b) == -1)
		return (-1);
	init_bench_disorder(a, &bench);
	test = 0;
	if (test)
	{
		printf("Stack a\n");
		print_stack(a);
		printf("Stack a status : %d\n", is_sorted(a, b));
		swap_top(a);
		print_stack(a);
		printf("post swap\n");
	}
	apply_strat(a, b, &move_count, bench);
	if (test)
	{
		print_stack(a);
		printf("Stack a status : %d\n", is_sorted(a, b));
	}
	if (bench.has_bench)
		print_bench(&bench, &move_count);
	free_stack(a);
	free_stack(b);
	return (0);
}
