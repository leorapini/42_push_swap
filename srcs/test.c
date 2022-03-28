/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:35:36 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/28 10:51:56 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_swap(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	printf("PRE SORT A\n");
	printf("len_a: %zu\n", *len_a);
	print_array(stack_a, *len_a);

	printf("\nPRE SORT B\n");
	printf("len_b: %zu\n", *len_b);
	print_array(stack_b, *len_b);
	printf("\n");

	push_b(stack_a, stack_b, len_a, len_b);
	push_b(stack_a, stack_b, len_a, len_b);
	swap_a(stack_a, *len_a);
	swap_b(stack_b, *len_b);
	push_a(stack_a, stack_b, len_a, len_b);

	printf("\nPOST SORT A\n");
	printf("len_a: %zu\n", *len_a);
	print_array(stack_a, *len_a);
	printf("\nPOST SORT B\n");
	printf("len_b: %zu\n", *len_b);
	print_array(stack_b, *len_b);
}
