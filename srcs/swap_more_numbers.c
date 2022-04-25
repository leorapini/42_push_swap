/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_more_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:47:27 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/25 12:43:18 by lpinheir         ###   ########.fr       */
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

static int	return_top_number(int *stack, size_t len, int	largest_number, int smallest_number)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (stack[i] != largest_number && stack[i] != smallest_number)
			break;
		i++;
	}
	return (stack[i]);
}

static int	return_bottom_number(int *stack, size_t len, int	largest_number, int smallest_number)
{
	size_t i;

	i = len -1;
	while (i > 0)
	{
		if (stack[i] != largest_number && stack[i] != smallest_number)
			break;
		i--;
	}
	return (stack[i]);
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
	int	distance;
	int	proximity_index;

	distance = 99999;
	proximity_index = 0;
	while (*len_b > 2)
	{
		proximity_index = return_proximity_index(stack_a, *len_a, stack_b[FIRST]);
		if (proximity_index < (int) *len_a / 2)
			distance = proximity_index;
		else
			distance = (int) *len_a - proximity_index;
		if (distance >= 20)
			rotate(stack_b, *len_b, "rb");
		else
			break ;
	}
}

// // Didn't add counter
// static void	find_shortest_distance(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
// {
// 	int	dist_current;
// 	int	dist_second;
// 	int	proximity_index_cur;
// 	int	proximity_index_sec;

// 	dist_current = 0;
// 	dist_second = 0;
// 	proximity_index_cur = 0;
// 	proximity_index_sec = 0;
// 	if (*len_b > 2)
// 	{
// 		proximity_index_cur = return_proximity_index(stack_a, *len_a, stack_b[FIRST]);
// 		proximity_index_sec = return_proximity_index(stack_a, *len_a, stack_b[SECOND]);
// 		if (proximity_index_cur < (int) *len_a / 2)
// 			dist_current = proximity_index_cur;
// 		else
// 			dist_current = (int) *len_a - proximity_index_cur;
// 		if (proximity_index_sec < (int) *len_a / 2)
// 			dist_second = proximity_index_sec;
// 		else
// 			dist_second = (int) *len_a - proximity_index_sec;
// 		// printf("cur_num: %d prox_ind: %d dist: %d\n", stack_b[FIRST], proximity_index_cur, dist_current);
// 		// printf("sec_num: %d prox_ind: %d dist: %d\n", stack_b[SECOND], proximity_index_sec, dist_second);
// 		if (proximity_index_sec < proximity_index_cur)
// 			swap(stack_b, *len_b, "sb");
// 	}
// }

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
	int	smallest_number_index;
	int	largest_number_index;
	int	current_len;
	int	average_value;
	int	current_first;
	int current_third;
	int	current_last;
	int	top_number;
	int bottom_number;
	int proximity_index;

	j = 0;
	i = 0;
	current_number = 0;
	original_len = *len_a;
	first_item = stack_a[FIRST];
	second_item = stack_a[SECOND];
	smallest_number = return_smallest_number(stack_a, *len_a);
	largest_number = return_largest_number(stack_a, *len_a);
	average_value = return_average_value(stack_a, *len_a);


	// PHASE ONE
	while (!(is_a_stack_sorted(stack_a, *len_a)) && i < original_len * 2)
	{
		if (*len_a == 3)
		{
			swap_three_numbers_a(stack_a, counter);
		}
		else if (stack_a[FIRST] > stack_a[*len_a - 1] || stack_a[FIRST] == largest_number)
		{
			*counter = *counter + 1;
			rotate(stack_a, *len_a, "ra");
		}
		else
		{
			*counter = *counter + 1;
			push_b(stack_a, stack_b, len_a, len_b);
		}
		i++;
	}

	// PHASE TWO
	while (*len_b > 0)
	{
		if (stack_b[FIRST] != smallest_number && original_len > 99)
			find_shortest_distance(stack_a, stack_b, len_a, len_b);
		current_number = stack_b[FIRST];
		i = 0;
		largest_number_index = return_largest_index(stack_a, *len_a);
		current_len = (int) *len_a;
		current_first = stack_a[FIRST];
		current_third = stack_a[THIRD];
		current_last = stack_a[*len_a - 1];
		top_number = return_top_number(stack_a, *len_a, largest_number, smallest_number);
		bottom_number = return_bottom_number(stack_a, *len_a, largest_number, smallest_number);
		proximity_index = return_proximity_index(stack_a, *len_a, current_number);
		// printf("--------\nARRAY A: ");
		// print_array(stack_a, *len_a);
		// printf("ARRAY B: ");
		// print_array(stack_b, *len_b);
		while (i < original_len)
		{
			if (current_number < stack_a[FIRST] && current_number > stack_a[*len_a - 1])
			{
				*counter = *counter + 1;
				push_a(stack_a, stack_b, len_a, len_b);
				break ;
			}
			else if (current_number < stack_a[SECOND] && stack_a[FIRST] == largest_number)
			{
				*counter = *counter + 2;
				push_a(stack_a, stack_b, len_a, len_b);
				swap(stack_a, *len_a, "sa");
				break ; 
			}
			else if (current_number > stack_a[FIRST] && current_number < stack_a[SECOND])
			{
				*counter = *counter + 2;
				push_a(stack_a, stack_b, len_a, len_b);
				swap(stack_a, *len_a, "sa");
				break ; 
			}
			else
			{
				// This can be done better. First choose what number to use (current, second or last)
				if (proximity_index > (int) *len_a / 2)
				{
					*counter = *counter + 1;
					reverse_rotate(stack_a, *len_a, "rra");
				}
				else
				{
					*counter = *counter + 1;
					rotate(stack_a, *len_a, "ra");
				}
			}
			i++;
		}
	}

	// PHASE THREE
	smallest_number_index = return_smallest_index(stack_a, *len_a);
	while (stack_a[FIRST] != smallest_number && stack_a[*len_a - 1] != largest_number)
	{
		if (smallest_number_index > (int) *len_a / 2)
		{
			*counter = *counter + 1;
			reverse_rotate(stack_a, *len_a, "rra");
		}
		else
		{
			*counter = *counter + 1;
			rotate(stack_a, *len_a, "ra");
		}
	}
}