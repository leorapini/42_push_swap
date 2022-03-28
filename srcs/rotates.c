/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:03:45 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/28 11:18:56 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int *stack_a, size_t current_len)
{
	size_t	i;
	int new_last;

	i = 0;
	if (current_len > 0)
	{
		new_last = stack_a[0];
		while (i < current_len - 1)
		{
			stack_a[i] = stack_a[i + 1];
			i++;
		}
		stack_a[i] = new_last;
		printf("ra\n");
	}
}

void	rotate_b(int *stack_b, size_t current_len)
{
	size_t	i;
	int new_last;

	i = 0;
	if (current_len > 0)
	{
		new_last = stack_b[0];
		while (i < current_len - 1)
		{
			stack_b[i] = stack_b[i + 1];
			i++;
		}
		stack_b[i] = new_last;
		printf("rb\n");
	}
}
