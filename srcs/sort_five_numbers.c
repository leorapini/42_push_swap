/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:52:19 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/27 18:38:23 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_smallest_index(int *stack_a, int current_len)
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

int	return_largest_index(int *stack_a, int current_len)
{
	int	i;
	int	largest_number;
	int	largest_index;

	i = 0;
	largest_number = -2147483646;
	largest_index = 0;
	while (i < current_len)
	{
		if (stack_a[i] > largest_number)
		{
			largest_number = stack_a[i];
			largest_index = i;
		}
		i++;
	}
	return (largest_index);
}

static void	push_the_smallest_to_b(int *stack_a, int *stack_b, size_t *len_a,
		size_t *len_b)
{
	int	i;
	int	smallest_index;

	i = 0;
	smallest_index = 0;
	while (i < 2)
	{
		smallest_index = return_smallest_index(stack_a, *len_a);
		if (smallest_index == FIRST)
			push_b(stack_a, stack_b, len_a, len_b);
		else if (smallest_index == SECOND)
		{
			swap(stack_a, *len_a, "sa");
			push_b(stack_a, stack_b, len_a, len_b);
		}
		else if (smallest_index == (int) *len_a - 1)
		{
			reverse_rotate(stack_a, *len_a, "rra");
			push_b(stack_a, stack_b, len_a, len_b);
		}
		else if (smallest_index == FOURTH)
		{
			reverse_rotate(stack_a, *len_a, "rra");
			reverse_rotate(stack_a, *len_a, "rra");
			push_b(stack_a, stack_b, len_a, len_b);
		}
		else
		{
			if (stack_a[SECOND] < stack_a[FIRST] && stack_a[SECOND]
				< stack_a[*len_a - 1])
				swap(stack_a, *len_a, "sa");
			else if (stack_a[*len_a - 1] < stack_a[FIRST] && stack_a[*len_a - 1]
				< stack_a[SECOND])
				reverse_rotate(stack_a, *len_a, "rra");
			push_b(stack_a, stack_b, len_a, len_b);
		}
		i++;
	}
}

static int	express_sorting_for_five(int *stack_a)
{
	if (stack_a[FIRST] < stack_a[SECOND] && stack_a[SECOND] < stack_a[THIRD]
		&& stack_a[THIRD] < stack_a[FOURTH])
	{
		if (stack_a[FIFTH] < stack_a[FIRST])
		{
			reverse_rotate(stack_a, 5, "rra");
			if (is_a_stack_sorted(stack_a, 5))
				return (1);
		}
	}
	if (stack_a[SECOND] < stack_a[THIRD] && stack_a[THIRD] < stack_a[FOURTH]
		&& stack_a[FOURTH] < stack_a[FIFTH])
	{
		if (stack_a[FIRST] > stack_a[FIFTH])
		{
			rotate(stack_a, 5, "ra");
			if (is_a_stack_sorted(stack_a, 5))
				return (1);
		}
	}
	if (stack_a[SECOND] < stack_a[THIRD] && stack_a[THIRD] < stack_a[FOURTH]
		&& stack_a[FOURTH] < stack_a[FIFTH])
	{
		if (stack_a[FIRST] > stack_a[SECOND] && stack_a[FIRST] < stack_a[THIRD])
		{
			swap(stack_a, 5, "sa");
			if (is_a_stack_sorted(stack_a, 5))
				return (1);
		}
	}
	return (0);
}

void	sort_five_numbers(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	int	i;
	int	current_number;
	int	smallest_number;

	i = 0;
	smallest_number = 0;
	if (!(express_sorting_for_five(stack_a)))
	{
		push_the_smallest_to_b(stack_a, stack_b, len_a, len_b);
		sort_three_numbers_a(stack_a);
		swap_two_numbers_b(stack_b);
		while (i < 2 && *len_b > 0)
		{
			current_number = stack_b[FIRST];
			if (current_number < stack_a[FIRST])
				push_a(stack_a, stack_b, len_a, len_b);
			else if (current_number > stack_a[*len_a - 1])
			{
				push_a(stack_a, stack_b, len_a, len_b);
				rotate(stack_a, *len_a, "ra");
			}
			else if (current_number > stack_a[FIRST] && current_number
				< stack_a[SECOND])
			{
				push_a(stack_a, stack_b, len_a, len_b);
				swap(stack_a, *len_a, "sa");
			}
			if (i == FIRST)
			{
				if (current_number > stack_a[SECOND] && current_number
					< stack_a[THIRD])
				{
					push_a(stack_a, stack_b, len_a, len_b);
					reverse_rotate(stack_a, *len_a, "rra");
					swap(stack_a, *len_a, "sa");
					rotate(stack_a, *len_a, "ra");
					rotate(stack_a, *len_a, "ra");
				}
			}
			else
			{
				if (current_number > stack_a[THIRD] && current_number
					< stack_a[FOURTH])
				{
					push_a(stack_a, stack_b, len_a, len_b);
					reverse_rotate(stack_a, *len_a, "rra");
					swap(stack_a, *len_a, "sa");
					rotate(stack_a, *len_a, "ra");
					rotate(stack_a, *len_a, "ra");
				}
				else if (current_number > stack_a[SECOND] && current_number
					< stack_a[THIRD])
				{
					push_a(stack_a, stack_b, len_a, len_b);
					reverse_rotate(stack_a, *len_a, "rra");
					swap(stack_a, *len_a, "sa");
					reverse_rotate(stack_a, *len_a, "rra");
					swap(stack_a, *len_a, "sa");
					reverse_rotate(stack_a, *len_a, "rra");
					reverse_rotate(stack_a, *len_a, "rra");
				}
			}
			i++;
		}
	}
}
