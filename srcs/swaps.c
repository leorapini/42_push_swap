/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:00:14 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/24 15:28:07 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *stack_a, size_t current_len)
{
	int	temp_0;

	if (current_len > 1)
	{
		temp_0 = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp_0;
		printf("sa\n");
	}
}

void	swap_b(int *stack_b, size_t current_len)
{
	int	temp_0;

	if (current_len > 1)
	{
		temp_0 = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp_0;
		printf("sb\n");
	}
}

void	swap_a_swap_b(int *stack_a, int *stack_b, size_t len_a, size_t len_b)
{
	swap_a(stack_a, len_a);
	swap_b(stack_b, len_b);
	printf("ss\n");
}
