/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:52:19 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/28 08:39:26 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_the_smallest_to_b_in_four(int *stack_a, int *stack_b,
	size_t *len_a, size_t *len_b)
{
	int	i;
	int	smallest_index;

	i = 0;
	smallest_index = 0;
	while (i < 1)
	{
		smallest_index = return_smallest_index(stack_a, *len_a);
		if (smallest_index == FIRST)
			push_b(stack_a, stack_b, len_a, len_b);
		else if (smallest_index == SECOND)
			sa_pb(stack_a, stack_b, len_a, len_b);
		else if (smallest_index == THIRD)
			rra_rra_pb(stack_a, stack_b, len_a, len_b);
		else
			rra_pb(stack_a, stack_b, len_a, len_b);
		i++;
	}
}

static int	express_sorting_for_four(int *stack_a, int current_len)
{
	if ((stack_a[FIRST] < stack_a[SECOND] && stack_a[SECOND] < stack_a[THIRD])
		&& (stack_a[FOURTH] < stack_a[FIRST]))
	{
		reverse_rotate(stack_a, current_len, "rra");
		if (is_a_stack_sorted(stack_a, current_len))
			return (1);
	}
	if ((stack_a[SECOND] < stack_a[THIRD] && stack_a[THIRD] < stack_a[FOURTH])
		&& (stack_a[FIRST] > stack_a[FOURTH]))
	{
		rotate(stack_a, current_len, "ra");
		if (is_a_stack_sorted(stack_a, current_len))
			return (1);
	}
	if ((stack_a[SECOND] < stack_a[THIRD] && stack_a[THIRD] < stack_a[FOURTH])
		&& (stack_a[FIRST] > stack_a[SECOND] && stack_a[FIRST]
			< stack_a[THIRD]))
	{
		printf("third");
		swap(stack_a, current_len, "sa");
		if (is_a_stack_sorted(stack_a, current_len))
			return (1);
	}
	return (0);
}

void	sort_four_numbers(int *stack_a, int *stack_b,
	size_t *len_a, size_t *len_b)
{
	int	i;
	int	current_number;
	int	smallest_number;

	i = 0;
	smallest_number = 0;
	if (!(express_sorting_for_four(stack_a, *len_a)))
	{
		push_the_smallest_to_b_in_four(stack_a, stack_b, len_a, len_b);
		sort_three_numbers_a(stack_a);
		while (i < 1 && *len_b > 0)
		{
			current_number = stack_b[FIRST];
			if (current_number < stack_a[FIRST])
				push_a(stack_a, stack_b, len_a, len_b);
			i++;
		}
	}
}
