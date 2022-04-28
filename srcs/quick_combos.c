/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_combos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:48:19 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/28 15:14:59 by lpinheir         ###   ########.fr       */
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

void	pa_ra(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	push_a(stack_a, stack_b, len_a, len_b);
	rotate(stack_a, *len_a, "ra");
}

void	pa_sa(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	push_a(stack_a, stack_b, len_a, len_b);
	swap(stack_a, *len_a, "sa");
}
