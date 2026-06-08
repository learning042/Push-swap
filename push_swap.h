/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:40:30 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/08 17:45:06 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int		*array;
	size_t	top;
	size_t	curr_size;
	size_t	max_size;
}	t_stack;

typedef enum	e_strategy
{
	Simple,
	Medium,
	Complex,
	Adaptative
}	t_strategy;

typedef struct	s_flags
{
	int	has_flags;
	int	bench;
	t_strategy	strategy;
}	t_flags;

typedef struct	s_move_count
{
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
	size_t	total;
}	t_move_count;

// movements
void	swap_a(t_stack *a, t_move_count *m);
void	swap_b(t_stack *b, t_move_count *m);
void	swap_both(t_stack *a, t_stack *b, t_move_count *m);
void	push_a(t_stack *a, t_stack *b, t_move_count *m);
void	push_b(t_stack *a, t_stack *b, t_move_count *m);
void	rotate_a(t_stack *a, t_move_count *m);
void	rotate_b(t_stack *b, t_move_count *m);
void	rotate_both(t_stack *a, t_stack *b, t_move_count *m);
void	rev_rotate_a(t_stack *a, t_move_count *m);
void	rev_rotate_b(t_stack *b, t_move_count *m);
void	rev_rotate_both(t_stack *a, t_stack *b, t_move_count *m);

// stack utils
void	print_stack(t_stack *s);
t_stack	*create_stack(int *nbrs, size_t nbr_count, size_t size);
void	init_stack(t_stack *s, int *arr);
void	free_stack(t_stack *s);
int		access_stack(t_stack *s, size_t i);
void	edit_stack(t_stack *s, size_t i, int n);
int		mod(int a, int b);
void	print_move_count(t_move_count *m);
void	rank_stack(t_stack *s);
int		ft_atoi(const char *nptr);
int		is_sorted(t_stack *s);

// algorithms
void	bucket_sort(t_stack *a, t_stack *b, t_move_count *move_count);
void	rev_insertion_sort(t_stack *a, t_stack *b, t_move_count *move_count);
void	insertion_sort(t_stack *a, t_stack *b, t_move_count *move_count);
void	radix_sort(t_stack *a, t_stack *b, t_move_count *move_count);
#endif
