/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:40:30 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/02 17:39:17 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int		*array;
	size_t	top;
	size_t	curr_size;
	size_t	max_size;
}	t_stack;

t_stack	*create_stack(int *nbrs, size_t nbr_count, size_t size);
void	init_stack(t_stack *s, int *arr);
void	print_stack(t_stack *s);
void	free_stack(t_stack *s);
int		access_stack(t_stack *s, size_t i);
void	edit_stack(t_stack *s, size_t i, int n);
int		mod(int a, int b);
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_both(t_stack *a, t_stack *b);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_both(t_stack *a, t_stack *b);
void	rev_rotate_a(t_stack *a);
void	rev_rotate_b(t_stack *b);
void	rev_rotate_both(t_stack *a, t_stack *b);
void	insertion_sort(t_stack *a, t_stack *b, size_t *move_count);
void	print_move_count(size_t *mv);
void	radix_sort(t_stack *a, t_stack *b, size_t *move_count);
void	rank_stack(t_stack *s);
int		ft_atoi(const char *nptr);
int		is_sorted(t_stack *s);
void	bucket_sort(t_stack *a, t_stack *b, size_t *move_count);
void	rev_insertion_sort(t_stack *a, t_stack *b, size_t *move_count);

#endif
