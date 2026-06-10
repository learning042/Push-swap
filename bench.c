/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:39:31 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/09 17:49:57 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(float disorder)
{
	const int	cent_disorder = (const int) (10000 * disorder);

	ft_printf("%d.%d%%\n", cent_disorder / 100, cent_disorder % 100);
	return ;
}

static void	print_strategy(t_bench *bench)
{
	const t_strategy strategy = bench->strategy;
	const float	disorder = bench->disorder;

	if (strategy == Simple)
		ft_printf("Simple / O(n\xc2\xb2)\n");
	if (strategy == Medium)
		ft_printf("Medium / O(n\xe2\x88\x9an)\n");
	if (strategy == Complex)
		ft_printf("Complex / O(n log n)\n");
	if (strategy == Adaptive)
	{
		ft_printf("Adaptive / ");
		if (disorder < 0.2)
			ft_printf("O(n\xc2\xb2)\n");
		if (0.2 <= disorder && disorder < 0.5)
			ft_printf("O(n\xe2\x88\x9an)\n");
		if (0.5 <= disorder)
			ft_printf("O(n log n)\n");
	}
	return ;
}

void	print_bench(t_bench *bench, t_move_count *moves)
{
	ft_printf("[bench] disorder:  ");
	print_disorder(bench->disorder);
	ft_printf("[bench] strategy: ");
	print_strategy(bench);
	print_move_count(moves);
}	
