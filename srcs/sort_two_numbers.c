/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:35:38 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/27 18:34:35 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  swap_two_numbers_b always puts the biggest number on top */
void	swap_two_numbers_b(int *stack)
{
	if (stack[0] < stack[1])
		swap(stack, 2, "sb");
}

void	sort_two_numbers_a(int *stack)
{
	if (stack[0] > stack[1])
		swap(stack, 2, "sa");
}
