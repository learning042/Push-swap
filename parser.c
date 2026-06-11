/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:48:50 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/11 17:55:03 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(int *array, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	safe_add(int a, int b, int *res)
{
	if (a > 0 && b > 0 && (a > INT_MAX - b))
		return (-1);
	if (a < 0 && b < 0 && (a < INT_MIN - b))
		return (-1);
	*res = a + b;
	return (0);
}

static int	safe_mult(int a, int b, int *res)
{
	if (a == 0 || b == 0)
	{
		*res = 0;
		return (0);
	}
	if (((a > 0 && b > 0) || (a < 0 && b < 0)) && (a <= INT_MAX / b))
	{
		*res = a * b;
		return (0);
	}
	if (((a > 0 && b < 0) || (a < 0 && b > 0)) && (a <= INT_MIN / b))
	{
		*res = a * b;
		return (0);
	}
	return (-1);
}
		
int	safe_atoi(char *str, int *val)
{
	size_t	i;
	int	sign;
	int	res;

	res = 0;
	i = (*str == '-');
	sign = 1 - 2 * i;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if (safe_mult(10, res, &res) == -1)
			return (-1);
		if (safe_add(res, sign * (str[i] - '0'), &res) == -1)
			return (-1);
		i++;
	}
	*val = res;
	return (0);
}

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static int	is_flag(char *s)
{
	if (ft_strcmp(s, "--bench") == 0)
		return (1);
	if (ft_strcmp(s, "--adaptive") == 0)
		return (1);
	if (ft_strcmp(s, "--simple") == 0)
		return (1);
	if (ft_strcmp(s, "--medium") == 0)
		return (1);
	if (ft_strcmp(s, "--complex") == 0)
		return (1);
	return (0);
}	

static int	update_bench_flags(char *s, t_bench *bench)
{
	if (ft_strcmp(s, "--bench") == 0)
	{
		if (bench->has_bench)
			return (-1);
		return (bench->has_bench = 1);
	}
	if (ft_strcmp(s, "--adaptive") == 0)
	{
		if (bench->is_adaptive)
			return (-1);
		return (bench->is_adaptive = 1);
	}
	if (bench->has_strategy)
		return (-1);
	if (ft_strcmp(s, "--simple") == 0)
		return (bench->is_adaptive = 0, bench->strategy = Simple, bench->has_strategy = 1);
	if (ft_strcmp(s, "--medium") == 0)
		return (bench->is_adaptive = 0, bench->strategy = Medium, bench->has_strategy = 1);
	if (ft_strcmp(s, "--complex") == 0)
		return (bench->is_adaptive = 0, bench->strategy = Complex, bench->has_strategy = 1);
	return (0);
}	

static void	init_bench(t_bench *bench)
{
	bench->has_bench = 0;
	bench->has_strategy = 0;
	bench->is_adaptive = 1;
	bench->strategy = Adaptive;
}

static int	build_stacks(int nbr_count, char **nbr_str, t_stack **a, t_stack **b)
{
	int	*nbrs;
	int	i;

	nbrs = malloc(sizeof(int) * nbr_count);
	i = 0;
	while (i < nbr_count)
	{
		if(safe_atoi(nbr_str[i], &nbrs[i]) == -1)
			return (ft_printf("Bad number error!\n"), -1);
		i++;
	}
	*a = create_stack(nbrs, nbr_count, nbr_count);
	*b = create_stack(NULL, 0, nbr_count);
	free(nbrs);
	return (0);
}

int	parser(int argc, char **argv, t_bench *bench, t_stack **a, t_stack **b)
{
	int	i;
	int	nbr_count;

	i = 1;
	init_bench(bench);
	while (i < argc - 1 && is_flag(argv[i]))
	{
		if (update_bench_flags(argv[i], bench) == -1)
		{
			printf("Flag parsing error!\n");
			return (-1);
		}
		i++;
	}
	nbr_count = argc - i;
	return (build_stacks(nbr_count, argv + i, a, b));
}

void	apply_strategy(t_stack *a, t_stack *b, t_move_count *move_count, t_bench bench)
{
	if (bench.strategy == Simple)
	{
		insertion_sort(a, b, move_count);
		return ;
	}
	if (bench.strategy == Medium)
	{
		bucket_sort(a, b, move_count);
		return ;
	}
	if (bench.strategy == Complex)
	{
		radix_sort(a, b, move_count);
		return ;
	}
}

/*	if (i > 3)
		return (printf("Too many flags!\n"), -1);
*/
