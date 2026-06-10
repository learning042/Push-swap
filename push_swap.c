/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:48:57 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/09 17:47:37 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*nbrs;
	size_t	nbr_count;
	t_stack	*a;
	t_stack	*b;
	t_move_count	move_count = {0};
	t_bench	bench;

	nbr_count = argc - 1;
	nbrs = malloc (sizeof(int) * (argc - 1));
	while (--argc)
		nbrs[argc - 1] = ft_atoi(argv[argc]);
	a = create_stack(nbrs, nbr_count, nbr_count);
	free(nbrs);
	bench.has_bench = 0;
	bench.has_strategy = 0;
	init_bench(a, &bench);
	printf("Stack a\n");
	print_stack(a);
	printf("Stack a status : %d\n", is_sorted(a));
	b = create_stack(NULL, 0, nbr_count);
	bucket_sort(a, b, &move_count);
	printf("move_count_total = %d\n", move_count.total);
	print_stack(a);
	printf("Stack a status : %d\n", is_sorted(a));
	print_bench(&bench, &move_count);
//	print_move_count(&move_count);
	free_stack(a);
	free_stack(b);
	return (0);
}
