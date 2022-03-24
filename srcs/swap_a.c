/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:00:14 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/24 14:09:30 by lpinheir         ###   ########.fr       */
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
	}
	
}