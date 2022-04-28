/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_combos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:48:19 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/28 07:54:03 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_pb(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	swap(stack_a, *len_a, "sa");
	push_b(stack_a, stack_b, len_a, len_b);
}

void	rra_rra_pb(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	reverse_rotate(stack_a, *len_a, "rra");
	reverse_rotate(stack_a, *len_a, "rra");
	push_b(stack_a, stack_b, len_a, len_b);
}

void	rra_pb(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	reverse_rotate(stack_a, *len_a, "rra");
	push_b(stack_a, stack_b, len_a, len_b);
}
