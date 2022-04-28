/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 08:53:37 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/28 15:09:08 by lpinheir         ###   ########.fr       */
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
