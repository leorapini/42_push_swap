/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:16:08 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/28 15:54:51 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* LIBRARIES */
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

/* DEFINES */
# define	START_ARGV 1
# define	FIRST 0
# define	SECOND 1
# define	THIRD 2
# define	FOURTH 3
# define	FIFTH 4

/* UTILS */
void	ft_error(int exit_code);
void	print_array(int *array, size_t len);
void	copy_to_stack_a(char **argv, int *stack_a, size_t len);
int		is_number_repeated(int *stack_a, long int number, size_t current_len);
int		is_a_stack_sorted(int *stack_a, size_t current_len);

/* STR UTILS */
int		is_argv_num(char **argv);
int		str_is_digit(char *s);

/* QUICK COMBOS */
void	sa_pb(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);
void	rra_rra_pb(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);
void	rra_pb(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);
void	pa_ra(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);
void	pa_sa(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);

/* BIG COMBOS */
void	pa_rra_sa_ra_ra(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);
void	pa_rra_sa_rra_sa_rra_rra(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);

/* SORT */
void	sort(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);

/* SORT UTILS */
int		return_smallest_index(int *stack_a, int current_len);
int		return_largest_index(int *stack_a, int current_len);

/* SWAP SORTING */
void	swap(int *stack, size_t current_len, char *operation);
void	swap_a_swap_b(int *stack_a, int *stack_b, size_t len_a, size_t len_b);

/* PUSH SORTING */
void	push_a(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);
void	push_b(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);

/* ROTATE SORTING */
void	rotate(int *stack, size_t current_len, char *operation);
void	rotate_a_rotate_b(int *stack_a, int *stack_b, size_t len_a,
			size_t len_b);

/* REVERSE ROTATE */
void	reverse_rotate(int *stack, size_t current_len, char *operation);
void	rev_rotate_a_rev_rotate_b(int *stack_a, int *stack_b, size_t len_a,
			size_t len_b);

/* SORT TWO NUMBERS */
void	sort_two_numbers_a(int *stack);
void	swap_two_numbers_b(int *stack);

/* SORT THREE NUMBERS */
void	sort_three_numbers_a(int *stack, int current_len);

/* SORT FOUR NUMBERS */
void	sort_four_numbers(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);

/* SORT FIVE NUMBERS */
void	sort_five_numbers(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);

/* SORT MORE NUMBERS */
void	sort_more_numbers(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);
int		return_average_value(int *stack_a, size_t len_a);

#endif
