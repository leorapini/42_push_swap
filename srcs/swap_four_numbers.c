/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_four_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:52:19 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/19 14:29:59 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	return_smallest_index(int *stack_a, int current_len)
{
	int	i;
	int	smallest;
	int	smallest_index;

	i = 0;
	smallest = 2147483647;
	smallest_index = 0;
	while (i < current_len)
	{
		if (stack_a[i] < smallest)
		{
			smallest = stack_a[i];
			smallest_index = i;
		}
		i++;
	}
	return (smallest_index);
}

static void	push_the_smallest_to_b_in_four(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b, int *counter)
{
	int	i;
	int	smallest_index;

	i = 0;
	smallest_index = 0;
	while (i < 1)
	{
		smallest_index = return_smallest_index(stack_a, *len_a);
		if (smallest_index == FIRST)
		{
			// printf("P2B: smallest_index (%d) == FIRST\n", smallest_index);
			*counter = *counter + 1;
			push_b(stack_a, stack_b, len_a, len_b);
		}
		else if (smallest_index == SECOND)
		{
			// printf("P2B: smallest_index (%d) == SECOND\n", smallest_index);
			*counter = *counter + 2;
			swap(stack_a, *len_a, "sa");
			push_b(stack_a, stack_b, len_a, len_b);
		}
		else if (smallest_index == (int) *len_a - 1)
		{
			// printf("P2B: smallest_index (%d) == %d\n", smallest_index, (int) *len_a - 1);
			*counter = *counter + 2;
			reverse_rotate(stack_a, *len_a, "rra");
			push_b(stack_a, stack_b, len_a, len_b);
		}
		else if (smallest_index == THIRD)
		{
			// printf("P2B: smallest_index (%d) == THIRD\n", smallest_index);
			*counter = *counter + 3;
			reverse_rotate(stack_a, *len_a, "rra");
			reverse_rotate(stack_a, *len_a, "rra");
			push_b(stack_a, stack_b, len_a, len_b);
		}
		// else
		// {
		// 	// printf("P2B: ELSE\n");
		// 	if (stack_a[SECOND] < stack_a[FIRST] && stack_a[SECOND] < stack_a[*len_a - 1])
		// 	{
		// 		*counter = *counter + 1;
		// 		swap(stack_a, *len_a, "sa");
		// 	}
		// 	else if (stack_a[*len_a - 1] < stack_a[FIRST] && stack_a[*len_a - 1] < stack_a[SECOND])
		// 	{
		// 		*counter = *counter + 1;
		// 		reverse_rotate(stack_a, *len_a, "rra");
		// 	}
		// 	*counter = *counter + 1;
		// 	push_b(stack_a, stack_b, len_a, len_b);
		// }
		i++;
	}
}

static int	express_sorting_for_four(int *stack_a, int *counter)
{
	if (stack_a[FIRST] < stack_a[SECOND] && stack_a[SECOND] < stack_a[THIRD])
		if (stack_a[FOURTH] < stack_a[FIRST])
		{
			*counter = *counter + 1;
			reverse_rotate(stack_a, 5, "rra");
			if (is_a_stack_sorted(stack_a, 5))
				return (1);
		}
	if (stack_a[SECOND] < stack_a[THIRD] && stack_a[THIRD] < stack_a[FOURTH])
		if (stack_a[FIRST] > stack_a[FOURTH])
		{
			*counter = *counter + 1;
			rotate(stack_a, 5, "ra");
			if (is_a_stack_sorted(stack_a, 5))
				return (1);
		}
	if (stack_a[SECOND] < stack_a[THIRD] && stack_a[THIRD] < stack_a[FOURTH])
		if (stack_a[FIRST] > stack_a[SECOND] && stack_a[FIRST] < stack_a[THIRD])
		{
			*counter = *counter + 1;
			swap(stack_a, 5, "sa");
			if (is_a_stack_sorted(stack_a, 5))
				return (1);
		}
	return (0);
}

void	four_numbers(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b, int *counter)
{
	int i;
	int	current_number;
	int smallest_number;

	i = 0;
	smallest_number = 0;
	if (!(express_sorting_for_four(stack_a, counter)))
		push_the_smallest_to_b_in_four(stack_a, stack_b, len_a, len_b, counter);
		// printf("Counter after push: %d\n", *counter);
		swap_three_numbers_a(stack_a, counter);
		// printf("Counter after swap3: %d\n", *counter);
		while (i < 1 && *len_b > 0)
		{
			current_number = stack_b[FIRST];
			if (current_number < stack_a[FIRST])
			{
				// printf("current_number < stack_a[FIRST]\n");
				*counter = *counter + 1;
				push_a(stack_a, stack_b, len_a, len_b);
			}
			else if (current_number > stack_a[*len_a - 1])
			{
				// printf("current_number > stack_a[*len_a - 1\n");
				*counter = *counter + 2;
				push_a(stack_a, stack_b, len_a, len_b);
				rotate(stack_a, *len_a, "ra");
			}
			else if (current_number > stack_a[FIRST] && current_number < stack_a[SECOND])
			{
				// printf("current_number > stack_a[FIRST] && current_number < stack_a[SECOND]\n");
				*counter = *counter + 2;
				push_a(stack_a, stack_b, len_a, len_b);
				swap(stack_a, *len_a, "sa");
			}
			// if (i == FIRST)
			// {
			// 	if (current_number > stack_a[SECOND] && current_number < stack_a[THIRD])
			// 	{
			// 		printf("i == FIRST | current_number > stack_a[SECOND] && current_number < stack_a[THIRD]\n");
			// 		*counter = *counter + 5;
			// 		push_a(stack_a, stack_b, len_a, len_b);
			// 		reverse_rotate(stack_a, *len_a, "rra");
			// 		swap(stack_a, *len_a, "sa");
			// 		rotate(stack_a, *len_a, "ra");
			// 		rotate(stack_a, *len_a, "ra");
			// 	}
			// }
			// else
			// {
			// 	if (current_number > stack_a[THIRD] && current_number < stack_a[FOURTH])
			// 	{
			// 		printf("ELSE | current_number > stack_a[THIRD] && current_number < stack_a[FOURTH]\n");
			// 		*counter = *counter + 5;
			// 		push_a(stack_a, stack_b, len_a, len_b);
			// 		reverse_rotate(stack_a, *len_a, "rra");
			// 		swap(stack_a, *len_a, "sa");
			// 		rotate(stack_a, *len_a, "ra");
			// 		rotate(stack_a, *len_a, "ra");
			// 	}
			// 	else if (current_number > stack_a[SECOND] && current_number < stack_a[THIRD])
			// 	{
			// 		// printf("ELSE | current_number > stack_a[SECOND] && current_number < stack_a[THIRD]\n");
			// 		*counter = *counter + 7;
			// 		push_a(stack_a, stack_b, len_a, len_b);
			// 		reverse_rotate(stack_a, *len_a, "rra");
			// 		swap(stack_a, *len_a, "sa");
			// 		reverse_rotate(stack_a, *len_a, "rra");
			// 		swap(stack_a, *len_a, "sa");
			// 		reverse_rotate(stack_a, *len_a, "rra");
			// 		reverse_rotate(stack_a, *len_a, "rra");
			// 	}
			// } 
			i++;
		}
}
