/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:11:49 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/12 17:52:24 by tpinto-v         ###   ########.fr       */
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

// Create stack
// READ operations from stdin until just click(or invalid input, in this case finish and print ERROR!) enter instead of move + enter
// Store each interation in a buffer
// Use the movements on the stack a / b
// IF stack a is sorted and stack b is empty
	// print OK!
//ELSE
	// print KO!

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
