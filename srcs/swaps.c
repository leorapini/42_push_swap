/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:00:14 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/04 11:49:10 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack, size_t current_len, char *operation)
{
	int	temp_0;

	if (current_len > 1)
	{
		temp_0 = stack[0];
		stack[0] = stack[1];
		stack[1] = temp_0;
		if (operation != NULL)
			printf("%s\n", operation);
	}
}

void	swap_a_swap_b(int *stack_a, int *stack_b, size_t len_a, size_t len_b)
{
	if (len_a > 0 || len_b > 0)
	{
		swap(stack_a, len_a, NULL);
		swap(stack_b, len_b, NULL);
		printf("ss\n");
	}
}
