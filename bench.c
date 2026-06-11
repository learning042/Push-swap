/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:39:31 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/11 18:00:27 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(t_rational disorder)
{
	int	num;
	int	den;
	int	before_period;
	int	after_period;

	num = disorder.num;
	den = disorder.den;
	before_period = (100 * num) / den;
	after_period = ((10000 * num) / den) % 100;
	ft_putnbr_fd(before_period, 2);
	ft_putchar_fd('.', 2);
	if (after_period < 10)
	{
		ft_putchar_fd('0', 2);
		ft_putnbr_fd(after_period, 2);
	}
	else
		ft_putnbr_fd(after_period, 2);
	ft_putstr_fd("%\n", 2);
	return ;
}

void	init_bench_disorder(t_stack *s, t_bench *bench)
{
	t_rational	disorder;
	int			num;
	int			den;

	disorder = compute_disorder(s);
	bench->disorder = disorder;
	num = disorder.num;
	den = disorder.den;
	if (!bench->is_adaptive)
		return ;
	if (5 * num < den)
		return ((void)(bench->strategy = Simple));
	if (2 * den <= 10 * num && 10 * num < 5 * den)
		return ((void)(bench->strategy = Medium));
	if (10 * num >= 5 * den)
		return ((void)(bench->strategy = Complex));
}

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
	ft_printf("[bench] disorder:  ");
	print_disorder(bench->disorder);
	ft_printf("[bench] strategy: ");
	print_strategy(bench);
	print_move_count(moves);
}
