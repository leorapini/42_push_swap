/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:52:19 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/28 16:09:31 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_the_smallest_to_b(int *stack_a, int *stack_b, size_t *len_a,
		size_t *len_b)
{
	int	smallest_index;

	smallest_index = 0;
	while (*len_a > 3)
	{
		smallest_index = return_smallest_index(stack_a, *len_a);
		if (smallest_index == FIRST)
			push_b(stack_a, stack_b, len_a, len_b);
		else if (smallest_index == SECOND)
			sa_pb(stack_a, stack_b, len_a, len_b);
		else if (smallest_index == FOURTH)
			rra_rra_pb(stack_a, stack_b, len_a, len_b);
		else if (smallest_index == (int) *len_a - 1)
			rra_pb(stack_a, stack_b, len_a, len_b);
		else if (stack_a[SECOND] < stack_a[FIRST] && stack_a[SECOND]
			< stack_a[*len_a - 1])
			sa_pb(stack_a, stack_b, len_a, len_b);
		else if (stack_a[*len_a - 1] < stack_a[FIRST] && stack_a[*len_a - 1]
			< stack_a[SECOND])
			rra_pb(stack_a, stack_b, len_a, len_b);
		else
			push_b(stack_a, stack_b, len_a, len_b);
	}
}

static int	express_sorting_for_five(int *stack_a, int current_len)
{
	if ((stack_a[FIRST] < stack_a[SECOND] && stack_a[SECOND] < stack_a[THIRD]
			&& stack_a[THIRD] < stack_a[FOURTH]) && (stack_a[FIFTH]
			< stack_a[FIRST]))
	{
		reverse_rotate(stack_a, current_len, "rra");
		if (is_a_stack_sorted(stack_a, current_len))
			return (1);
	}
	if ((stack_a[SECOND] < stack_a[THIRD] && stack_a[THIRD] < stack_a[FOURTH]
			&& stack_a[FOURTH] < stack_a[FIFTH]) && (stack_a[FIRST]
			> stack_a[FIFTH]))
	{
		rotate(stack_a, current_len, "ra");
		if (is_a_stack_sorted(stack_a, current_len))
			return (1);
	}
	if ((stack_a[SECOND] < stack_a[THIRD] && stack_a[THIRD] < stack_a[FOURTH]
			&& stack_a[FOURTH] < stack_a[FIFTH]) && (stack_a[FIRST]
			> stack_a[SECOND] && stack_a[FIRST] < stack_a[THIRD]))
	{
		swap(stack_a, current_len, "sa");
		if (is_a_stack_sorted(stack_a, current_len))
			return (1);
	}
	return (0);
}

void	sort_five_numbers(int *stack_a, int *stack_b, size_t *len_a,
	size_t *len_b)
{
	int	current_number;

	if (!(express_sorting_for_five(stack_a, *len_a)))
	{
		push_the_smallest_to_b(stack_a, stack_b, len_a, len_b);
		sort_three_numbers_a(stack_a, *len_a);
		swap_two_numbers_b(stack_b);
		while (*len_a < 5 && *len_b > 0)
		{
			current_number = stack_b[FIRST];
			if (current_number < stack_a[FIRST])
				push_a(stack_a, stack_b, len_a, len_b);
			else if (current_number > stack_a[*len_a - 1])
				pa_ra(stack_a, stack_b, len_a, len_b);
			else if (current_number > stack_a[FIRST] && current_number
				< stack_a[SECOND])
				pa_sa(stack_a, stack_b, len_a, len_b);
			else if ((*len_a == 3) && (current_number > stack_a[SECOND]
					&& current_number < stack_a[THIRD]))
				pa_rra_sa_ra_ra(stack_a, stack_b, len_a, len_b);
			else
			{
				if (current_number > stack_a[THIRD] && current_number
					< stack_a[FOURTH])
					pa_rra_sa_ra_ra(stack_a, stack_b, len_a, len_b);
				else if (current_number > stack_a[SECOND] && current_number
					< stack_a[THIRD])
					pa_rra_sa_rra_sa_rra_rra(stack_a, stack_b, len_a, len_b);
			}
		}
	}
}
