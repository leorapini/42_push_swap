/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:16:08 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/27 18:06:15 by lpinheir         ###   ########.fr       */
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

/* SORT */
void	sort(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);

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

/* SWAP TWO NUMBERS */
void	swap_two_numbers_a(int *stack);
void	swap_two_numbers_b(int *stack);

/* SWAP THREE NUMBERS */
void	swap_three_numbers_a(int *stack);

/* SWAP FOUR NUMBERS */
void	four_numbers(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);

/* SWAP FIVE NUMBERS */
void	five_numbers(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);
int		return_smallest_index(int *stack_a, int current_len);
int		return_largest_index(int *stack_a, int current_len);

/* SWAP MORE NUMBERS */
void	more_numbers(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b);
int		return_average_value(int *stack_a, size_t len_a);

#endif
