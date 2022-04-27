/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_more_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:47:27 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/27 18:13:03 by lpinheir         ###   ########.fr       */
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

int		return_average_value(int *stack_a, size_t len_a)
{
	size_t	i;
	int	total_value;
	
	i = 0;
	total_value = 0;
	while (i < len_a)
	{
		total_value = total_value + stack_a[i];
		i++;
	}
	return (total_value / (int) len_a);
}

static int	return_proximity_index(int *stack, size_t len, int current_number)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if ((current_number > stack[i] && current_number < stack[i + 1]))
			break ;
		i++;
	}
	return (i + 1);
}

// Didn't add counter
static void	find_shortest_distance(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	int	i;
	int	distance;
	int	distance_last;
	int	distance_sec;
	int	proximity_index;
	int prox_index_last;
	int	prox_index_sec;

	i = 0;
	while (*len_b > 2 && *len_a > 7 && i < (int) *len_b)
	{
		proximity_index = return_proximity_index(stack_a, *len_a, stack_b[FIRST]);
		prox_index_last = return_proximity_index(stack_a, *len_a, stack_b[*len_b - 1]);
		prox_index_sec = return_proximity_index(stack_a, *len_a, stack_b[SECOND]);
		if (proximity_index < (int) *len_a / 2)
			distance = proximity_index;
		else
			distance = (int) *len_a - proximity_index;
		if (prox_index_last < (int) *len_a / 2)
			distance_last = prox_index_last;
		else
			distance_last = (int) *len_a - prox_index_last;
		if (prox_index_sec < (int) *len_a / 2)
			distance_sec = prox_index_sec;
		else
			distance_sec = (int) *len_a - prox_index_sec;
		if (distance <= distance_last && distance <= distance_sec)
		{
			if (distance <= (int) *len_a / 5)
				break;
		}
		if (distance_last <= distance && distance_last <= distance_sec)
		{
			if (distance_last <= (int) *len_a / 5)
			{
				reverse_rotate(stack_b, *len_b, "rrb");
				break;
			}
		}
		if (distance_sec < distance && distance_sec < distance_last)
		{
			if (distance_sec <= (int) *len_a / 5)
			{
				rotate(stack_b, *len_b, "rb");
				break;
			}
		}
		rotate(stack_b, *len_b, "rb");
		i++;
	}
}

void	more_numbers(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	size_t	i;
	int	j;
	int	smallest_number;
	int	largest_number;
	size_t original_len;
	int	first_item;
	int	second_item;
	int	current_number;
	int	smallest_number_index;
	int	largest_number_index;
	int	current_len;
	int	current_first;
	int current_third;
	int	current_last;
	int proximity_index;
	int first_sort;

	j = 0;
	i = 0;
	current_number = 0;
	original_len = *len_a;
	first_item = stack_a[FIRST];
	second_item = stack_a[SECOND];
	smallest_number = return_smallest_number(stack_a, *len_a);
	largest_number = return_largest_number(stack_a, *len_a);
	first_sort = 1;
	


	// PHASE ONE
	while (!(is_a_stack_sorted(stack_a, *len_a)) && i < original_len * 2)
	{
		// make it in a way that it rotates medium numbers and not large ones
		if (*len_a == original_len && first_sort)
		{
			first_sort = 0;
			if (stack_a[0] < stack_a[1] && stack_a[0] < stack_a[2] && stack_a[0] < stack_a[*len_a - 1])
				rotate(stack_a, *len_a, "ra");
			else if (stack_a[1] < stack_a[0] && stack_a[1] < stack_a[2] && stack_a[1] < stack_a[*len_a - 1])
			{
				swap(stack_a, *len_a, "sa");
				rotate(stack_a, *len_a, "ra");
			}
			else if (stack_a[2] < stack_a[0] && stack_a[2] < stack_a[1] && stack_a[2] < stack_a[*len_a - 1])
			{
				rotate(stack_a, *len_a, "ra");
				rotate(stack_a, *len_a, "ra");
			}
		}
		else if (*len_a == 3)
			swap_three_numbers_a(stack_a);
		else if (stack_a[SECOND] < stack_a[FIRST] && stack_a[SECOND] > stack_a[*len_a - 1])
		{
			swap(stack_a, *len_a, "sa");
			rotate(stack_a, *len_a, "ra");
		}
		else if (stack_a[FIRST] > stack_a[*len_a - 1] || stack_a[FIRST] == largest_number)
			rotate(stack_a, *len_a, "ra");
		else
			push_b(stack_a, stack_b, len_a, len_b);
		i++;
	}


	// PHASE TWO
	while (*len_b > 0)
	{
		if (stack_b[FIRST] != smallest_number)
			find_shortest_distance(stack_a, stack_b, len_a, len_b);
		else 
			rotate(stack_b, *len_b, "rb");
		current_number = stack_b[FIRST];
		i = 0;
		largest_number_index = return_largest_index(stack_a, *len_a);
		current_len = (int) *len_a;
		current_first = stack_a[FIRST];
		current_third = stack_a[THIRD];
		current_last = stack_a[*len_a - 1];
		proximity_index = return_proximity_index(stack_a, *len_a, current_number);
		while (i < original_len)
		{
			// printf("\n");
			// printf("--------\nARRAY A: ");
			// print_array(stack_a, *len_a);
			// printf("ARRAY B: ");
			// print_array(stack_b, *len_b);
			if (current_number < stack_a[FIRST] && current_number > stack_a[*len_a - 1])
			{
				push_a(stack_a, stack_b, len_a, len_b);
				break ;
			}
			else if (current_number < stack_a[SECOND] && stack_a[FIRST] == largest_number)
			{
				rotate(stack_a, *len_a, "ra");
				push_a(stack_a, stack_b, len_a, len_b);
				// swap(stack_a, *len_a, "sa");
				break ; 
			}
			else if (current_number > stack_a[FIRST] && current_number < stack_a[SECOND])
			{
				rotate(stack_a, *len_a, "ra");
				push_a(stack_a, stack_b, len_a, len_b);
				// swap(stack_a, *len_a, "sa");
				break ; 
			}
			else
			{
				if (proximity_index > (int) *len_a / 2)
					reverse_rotate(stack_a, *len_a, "rra");
				else
					rotate(stack_a, *len_a, "ra");
			}
			i++;
		}
	}

	// PHASE THREE
	smallest_number_index = return_smallest_index(stack_a, *len_a);
	while (stack_a[FIRST] != smallest_number && stack_a[*len_a - 1] != largest_number)
	{
		if (smallest_number_index > (int) *len_a / 2)
			reverse_rotate(stack_a, *len_a, "rra");
		else

			rotate(stack_a, *len_a, "ra");
	}
}