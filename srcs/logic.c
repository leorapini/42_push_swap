/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:27:08 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/24 15:25:18 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_it(int *stack_a, int *stack_b, size_t len_a, size_t len_b)
{
	if (len_b > 50)
		printf("%d", stack_b[0]);
	test_swap(stack_a, stack_b, len_a, len_b);
}
