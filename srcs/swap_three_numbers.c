/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:39:43 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/18 19:32:22 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_three_numbers_a(int *stack, int *counter)
{
	if (stack[FIRST] > stack[SECOND] && stack[THIRD] > stack[FIRST])
	{
		*counter = *counter + 1;
		swap(stack, 3, "sa");
	}
	else if (stack[FIRST] > stack[SECOND] && stack[THIRD] < stack[SECOND])
	{
		*counter = *counter + 2;
		rotate(stack, 3, "ra");
		swap(stack, 3, "sa");
	}
	else if (stack[FIRST] > stack[SECOND] && stack[THIRD] > stack[SECOND])
	{
		*counter = *counter + 1;
		rotate(stack, 3, "ra");
	}
	else if (stack[FIRST] < stack[SECOND] && stack[THIRD] < stack[FIRST])
	{
		*counter = *counter + 1;
		reverse_rotate(stack, 3, "rra");
	}
	else if (stack[FIRST] < stack[SECOND] && stack[THIRD] < stack[SECOND])
	{
		*counter = *counter + 2;
		swap(stack, 3, "sa");
		rotate(stack, 3, "ra");
	}
}