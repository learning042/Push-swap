/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:46:48 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/06/13 12:51:16 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compute_disorder(t_stack *s, t_rational *val)
{
	size_t		mistakes;
	size_t		i;
	size_t		j;
	t_rational	disorder;

	if (s->curr_size <= 1)
		return (disorder.num = 0, disorder.den = 1, (void)(*val = disorder));
	mistakes = 0;
	i = 0;
	while (i < s->curr_size)
	{
		j = i + 1;
		while (j < s->curr_size)
		{
			if (access_stack(s, i) > access_stack(s, j))
				++mistakes;
			++j;
		}
		++i;
	}
	disorder.num = mistakes;
	disorder.den = (s->curr_size * (s->curr_size - 1)) / 2;
	*val = disorder;
	return ;
}

void	init_bench_disorder(t_stack *s, t_bench *bench)
{
	t_rational	disorder;
	int			num;
	int			den;

	compute_disorder(s, &disorder);
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

void	print_disorder(t_rational disorder)
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
