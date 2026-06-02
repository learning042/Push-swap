/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:48:57 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/02 13:41:34 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*nbrs;
	size_t	nbr_count;
	t_stack	*a;
	t_stack	*b;
	size_t	move_count[11] = {0};

	nbr_count = argc - 1;
	nbrs = malloc (sizeof(int) * (argc - 1));
	while (--argc)
		nbrs[argc - 1] = ft_atoi(argv[argc]);
	a = create_stack(nbrs, nbr_count, nbr_count);
	free(nbrs);
	printf("Stack a\n");
	print_stack(a);
	printf("Stack a status : %d\n", is_sorted(a));
	b = create_stack(NULL, 0, nbr_count);
	radix_sort(a, b, move_count);
	print_stack(a);
	printf("Stack a status : %d\n", is_sorted(a));
	print_move_count(move_count);
	free_stack(a);
	free_stack(b);
	return (0);
}
