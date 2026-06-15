/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:39:31 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/13 18:36:52 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_strategy(t_bench *bench)
{
	const t_strategy	strategy = bench->strategy;

	if (bench->is_adaptive)
		ft_putstr_fd("Adaptive / ", 2);
	if (strategy == Simple)
	{
		if (!bench->is_adaptive)
			ft_putstr_fd("Simple / ", 2);
		ft_putstr_fd("O(n\xc2\xb2)\n", 2);
	}
	if (strategy == Medium)
	{
		if (!bench->is_adaptive)
			ft_putstr_fd("Medium /", 2);
		ft_putstr_fd("O(n\xe2\x88\x9an)\n", 2);
	}
	if (strategy == Complex)
	{
		if (!bench->is_adaptive)
			ft_putstr_fd("Complex /", 2);
		ft_putstr_fd("O(n log n)\n", 2);
	}
	return ;
}

void	print_bench(t_bench *bench, t_move_count *moves)
{
	ft_putstr_fd("[bench] disorder:  ", 2);
	print_disorder(bench->disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	print_strategy(bench);
	print_move_count(moves);
}
