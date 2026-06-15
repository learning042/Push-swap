/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:48:50 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/13 19:42:45 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	update_bench_flags(char *s, t_bench *bench)
{
	t_bench	*b;

	b = bench;
	if (ft_strcmp(s, "--bench") == 0)
	{
		if (b->has_bench)
			return (-1);
		return (b->has_bench = 1);
	}
	if (b->has_strategy)
		return (-1);
	if (ft_strcmp(s, "--adaptive") == 0)
		return (b->has_strategy = 1);
	if (ft_strcmp(s, "--simple") == 0)
		return (b->is_adaptive = 0, b->strategy = Simple, b->has_strategy = 1);
	if (ft_strcmp(s, "--medium") == 0)
		return (b->is_adaptive = 0, b->strategy = Medium, b->has_strategy = 1);
	if (ft_strcmp(s, "--complex") == 0)
		return (b->is_adaptive = 0, b->strategy = Complex, b->has_strategy = 1);
	return (0);
}

static void	init_bench(t_bench *bench)
{
	bench->has_bench = 0;
	bench->has_strategy = 0;
	bench->is_adaptive = 1;
	bench->strategy = Adaptive;
}

int	build_stacks(int nbr_count, char **nbr_str, t_stack **a, t_stack **b)
{
	int	*nbrs;
	int	i;

	nbrs = malloc(sizeof(int) * nbr_count);
	i = 0;
	while (i < nbr_count)
	{
		if (safe_atoi(nbr_str[i], &nbrs[i]) == -1)
			return (ft_putstr_fd("Error\n", 2), -1);
		i++;
	}
	if (has_duplicate(nbrs, nbr_count))
		return (ft_putstr_fd("Error\n", 2), -1);
	*a = create_stack(nbrs, nbr_count, nbr_count);
	*b = create_stack(NULL, 0, nbr_count);
	free(nbrs);
	return (0);
}

int	parser(int argc, char **argv, t_bench *bench, int *first_nbr)
{
	int	i;

	i = 1;
	init_bench(bench);
	while (i < argc - 1 && is_flag(argv[i]))
	{
		if (update_bench_flags(argv[i], bench) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		i++;
	}
	*first_nbr = i;
	return (0);
}

void	apply_strat(t_stack *a, t_stack *b, t_move_count *move, t_bench bench)
{
	if (bench.strategy == Simple)
	{
		insertion_sort(a, b, move);
		return ;
	}
	if (bench.strategy == Medium)
	{
		bucket_sort(a, b, move);
		return ;
	}
	if (bench.strategy == Complex)
	{
		radix_sort(a, b, move);
		return ;
	}
}
