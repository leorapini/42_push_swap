/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_more_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:47:27 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/21 20:11:23 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	return_smallest_number(int *stack, int len)
{
	int	i;
	int	smallest_number;

	i = 0;
	smallest_number = 2147483647;
	while (i < len)
	{
		if (stack[i] < smallest_number)
			smallest_number = stack[i];
		i++;
	}
	return (smallest_number);
}

static int	return_largest_number(int *stack, int len)
{
	int	i;
	int	largest_number;

	i = 0;
	largest_number = -2147483646;
	while (i < len)
	{
		if (stack[i] > largest_number)
			largest_number = stack[i];
		i++;
	}
	return (largest_number);
}

void	more_numbers(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b, int *counter)
{
	size_t	i;
	int	j;
	int	smallest_number;
	int	largest_number;
	size_t original_len;
	int	first_item;
	int	second_item;
	int	current_number;

	j = 0;
	i = 0;
	current_number = 0;
	original_len = *len_a;
	first_item = stack_a[FIRST];
	second_item = stack_a[SECOND];
	smallest_number = return_smallest_number(stack_a, *len_a);
	largest_number = return_largest_number(stack_a, *len_a);
	// printf("smallest_number: %d\n", smallest_number);
	// printf("largest_number: %d\n", largest_number);
	while (!(is_a_stack_sorted(stack_a, *len_a)) && i < original_len * 2)
	{
		// printf("--------\nARRAY A: ");
		// print_array(stack_a, *len_a);
		// printf("ARRAY B: ");
		// print_array(stack_b, *len_b);
		if (stack_a[FIRST] > stack_a[*len_a - 1] || stack_a[FIRST] == largest_number)
		{
			*counter = *counter + 1;
			rotate(stack_a, *len_a, "ra");
		}
		// else if (stack_a[FIRST] > stack_a[SECOND] || stack_a[FIRST] != largest_number)
		// {
		// 	*counter = *counter + 3;
		// 	swap(stack_a, *len_a, "sa");
		// 	rotate(stack_a, *len_a, "ra");
		// 	push_b(stack_a, stack_b, len_a, len_b);
		// }
		else
		{
			*counter = *counter + 1;
			push_b(stack_a, stack_b, len_a, len_b);
		}
		i++;
	}
	// rotate(stack_a, *len_a, "ra");
	// printf("%zu\n", i);
	// printf("--------\nARRAY A: ");
	// print_array(stack_a, *len_a);
	// printf("ARRAY B: ");
	// print_array(stack_b, *len_b);
	// printf("\nSTART OF PHASE TWO\n\n");
	// i = 30;
	while (*len_b > 0)
	{
		current_number = stack_b[FIRST];
		// printf("current_number (%d)\n", current_number);
		// printf("ARRAY B: ");
		// print_array(stack_b, *len_b);
		// printf("ARRAY A: ");
		// print_array(stack_a, *len_a);
		// printf("\n");
		if (current_number == smallest_number && *len_b > 1)
		{
			*counter = *counter + 1;
			rotate(stack_b, *len_b, "rb");
		}
		else if (current_number == smallest_number && *len_b == 1)
		{
			while (largest_number != stack_a[*len_a - 1])
			{
				*counter = *counter + 1;	
				rotate(stack_a, *len_a, "ra");
			}
			*counter = *counter + 1;
			push_a(stack_a, stack_b, len_a, len_b);
		}
		else if (current_number > stack_a[FIRST] && current_number < stack_a[SECOND])
		{
			*counter = *counter + 2;
			push_a(stack_a, stack_b, len_a, len_b);
			swap(stack_a, *len_a, "sa");
		}
		else if (current_number < stack_a[FIRST] && largest_number == stack_a[*len_a - 1])
		{
			*counter = *counter + 1;
			push_a(stack_a, stack_b, len_a, len_b);
		}
		else
		{
			*counter = *counter + 1;
			rotate(stack_a, *len_a, "ra");
		}
		// printf("\n");
	}
	// printf("counter: %d\n", *counter);
	// printf("--------\nARRAY A: ");
	// print_array(stack_a, *len_a);
	// printf("ARRAY B: ");
	// print_array(stack_b, *len_b);
}