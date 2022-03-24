/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:35:36 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/24 14:41:39 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_swap(int *stack_a, int *stack_b, size_t len_a, size_t len_b)
{
	printf("PRE SORT\n");
	print_array(stack_a, len_a);

	swap_a_swap_b(stack_a, stack_b, len_a, len_b);

	printf("\nPOST SORT\n");
	print_array(stack_a, len_a);
}