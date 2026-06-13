/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:48:57 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/13 15:44:06 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	/*
	int		*nbrs;
	size_t	nbr_count;
	*/
	t_stack	*a;
	t_stack	*b;
	t_move_count	move_count = {0};
	t_bench	bench;
	int	test;
	
	if (parser(argc, argv, &bench, &a, &b) == -1)
		return (-1);
	
	/*
	nbr_count = argc - 1;
	nbrs = malloc (sizeof(int) * (argc - 1));
	while (--argc)
	{
		if (safe_atoi(argv[argc], &nbrs[argc - 1]) == -1)
			return(ft_printf("Error!\n"), 1);
	}

	a = create_stack(nbrs, nbr_count, nbr_count);
	b = create_stack(NULL, 0, nbr_count);
	free(nbrs);
	bench.has_bench = 0;
	bench.has_strategy = 0;
*/	init_bench_disorder(a, &bench);
	test = 0;
	if (test)
	{
		printf("Stack a\n");
		print_stack(a);
	//	printf("Stack a status : %d\n", is_sorted(a));
	}
	apply_strategy(a, b, &move_count, bench);	
	if (test)
	{
		print_stack(a);
	//	printf("Stack a status : %d\n", is_sorted(a));
	}
	if (bench.has_bench)
		print_bench(&bench, &move_count);
	free_stack(a);
	free_stack(b);
	return (0);
}
