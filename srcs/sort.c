/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:27:08 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/27 18:04:41 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	if (is_a_stack_sorted(stack_a, *len_a))
		printf("Stack is sorted\n");
	else if (*len_a == 2)
		swap_two_numbers_a(stack_a);
	else if (*len_a == 3)
		swap_three_numbers_a(stack_a);
	else if (*len_a == 4)
		four_numbers(stack_a, stack_b, len_a, len_b);
	else if (*len_a == 5)
		five_numbers(stack_a, stack_b, len_a, len_b);
	else
		more_numbers(stack_a, stack_b, len_a, len_b);
	// if (is_a_stack_sorted(stack_a, *len_a))
	// 	printf("\nSUCCESS!\n");
	// else
	// 	printf("\nFAIL FAIL FAIL FAIL\n");
	// printf("\n");
	// printf("--------\nARRAY A: ");
	// print_array(stack_a, *len_a);
	// printf("ARRAY B: ");
	// print_array(stack_b, *len_b);
}