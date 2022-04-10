/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:27:08 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/10 17:47:35 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_three_numbers(int *stack)
{
	if (stack[0] > stack[1] && stack[2] > stack[0])
		swap(stack, 3, "sa");
	else if (stack[0] > stack[1] && stack[2] < stack[1])
	{
		rotate(stack, 3, "ra");
		swap(stack, 3, "sa");
	}
	else if (stack[0] > stack[1] && stack[2] > stack[1])
		rotate(stack, 3, "ra");
	else if (stack[0] < stack[1] && stack[2] < stack[0])
		reverse_rotate(stack, 3, "rra");
	else if (stack[0] < stack[1] && stack[2] < stack[1])
	{
		swap(stack, 3, "sa");
		rotate(stack, 3, "ra");
	}
	else
		printf("eita\n");
}

static void	swap_two_numbers(int *stack)
{
	if (stack[0] > stack[1])
		swap(stack, 2, "sa");
}

void	swap_it(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	if (is_a_stack_sorted(stack_a, *len_a))
		printf("Stack is sorted\n");
	else if (*len_a == 2)
		swap_two_numbers(stack_a);
	else if (*len_a == 3)
		swap_three_numbers(stack_a);
	else
	{
		printf("Stack is not sorted\n");
		test_swap(stack_a, stack_b, len_a, len_b);
	}
	printf("\n");
	printf("--------\n");
	print_array(stack_a, *len_a);
}
