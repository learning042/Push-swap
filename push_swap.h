/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:40:30 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/13 15:49:22 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int		*array;
	size_t	top;
	size_t	curr_size;
	size_t	max_size;
}	t_stack;

typedef enum e_strategy
{
	Simple,
	Medium,
	Complex,
	Adaptive
}	t_strategy;

typedef struct s_rational
{
	int	num;
	int	den;
}	t_rational;

typedef struct s_bench
{
	int			has_bench;
	int			has_strategy;
	int			is_adaptive;
	t_rational	disorder;
	t_strategy	strategy;
}	t_bench;

typedef struct s_move_count
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_move_count;

// movements
void	swap_top(t_stack *s);
void	swap_a(t_stack *a, t_move_count *m);
void	swap_b(t_stack *b, t_move_count *m);
void	swap_both(t_stack *a, t_stack *b, t_move_count *m);
void	push(t_stack *a, t_stack *b);
void	push_a(t_stack *a, t_stack *b, t_move_count *m);
void	push_b(t_stack *a, t_stack *b, t_move_count *m);
void	rotate(t_stack *s);
void	rotate_a(t_stack *a, t_move_count *m);
void	rotate_b(t_stack *b, t_move_count *m);
void	rotate_both(t_stack *a, t_stack *b, t_move_count *m);
void	rev_rotate(t_stack *s);
void	rev_rotate_a(t_stack *a, t_move_count *m);
void	rev_rotate_b(t_stack *b, t_move_count *m);
void	rev_rotate_both(t_stack *a, t_stack *b, t_move_count *m);

// parsing

int	has_duplicate(int *array, size_t len);
int	safe_atoi(char *str, int *val);
int	ft_strcmp(char *s1, char *s2);
void	apply_strategy(t_stack *a, t_stack *b, t_move_count *move_count, t_bench bench);
int	build_stacks(int nbr_count, char **nbr_str, t_stack **a, t_stack **b);
int	parser(int argc, char **argv, t_bench *bench, t_stack **a, t_stack **b);

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
int		is_sorted(t_stack *a, t_stack *b);

// algorithms
void	bucket_sort(t_stack *a, t_stack *b, t_move_count *move_count);
void	rev_insertion_sort(t_stack *a, t_stack *b, t_move_count *move_count);
void	insertion_sort(t_stack *a, t_stack *b, t_move_count *move_count);
void	radix_sort(t_stack *a, t_stack *b, t_move_count *move_count);

// benchmark

t_rational	compute_disorder(t_stack *s);
void	print_bench(t_bench *bench, t_move_count *moves);
void	init_bench_disorder(t_stack *s, t_bench *bench);
#endif
