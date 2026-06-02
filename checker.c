/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:11:49 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/02 13:35:26 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	size_t	i;

	i = 0;
	if (s->curr_size < 2)
		return (1);
	while (i + 1 < s->curr_size)
	{
		if (access_stack(s, i) > access_stack(s, i + 1))
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(int argc, char **argv)
{
	int		*nbrs;
	size_t	nbr_count;
	t_stack 	*a;

	nbr_count = argc - 1;
	nbrs = malloc(sizeof(int) * nbr_count);
	while (--argc)
		nbrs[argc - 1] = ft_atoi(argv[argc]);
	a = create_stack(nbrs, nbr_count, nbr_count);
*/
