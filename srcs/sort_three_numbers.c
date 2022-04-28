/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:39:43 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/28 09:55:21 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers_a(int *stack, int current_len)
{
	if (current_len != 3)
		ft_error(1);
	if (stack[FIRST] > stack[SECOND] && stack[THIRD] > stack[FIRST])
		swap(stack, 3, "sa");
	else if (stack[FIRST] > stack[SECOND] && stack[THIRD] < stack[SECOND])
	{
		rotate(stack, 3, "ra");
		swap(stack, 3, "sa");
	}
	else if (stack[FIRST] > stack[SECOND] && stack[THIRD] > stack[SECOND])
		rotate(stack, 3, "ra");
	else if (stack[FIRST] < stack[SECOND] && stack[THIRD] < stack[FIRST])
		reverse_rotate(stack, 3, "rra");
	else if (stack[FIRST] < stack[SECOND] && stack[THIRD] < stack[SECOND])
	{
		swap(stack, 3, "sa");
		rotate(stack, 3, "ra");
	}
}
