/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_combos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:49:30 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/28 15:53:25 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_rra_sa_ra_ra(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	push_a(stack_a, stack_b, len_a, len_b);
	reverse_rotate(stack_a, *len_a, "rra");
	swap(stack_a, *len_a, "sa");
	rotate(stack_a, *len_a, "ra");
	rotate(stack_a, *len_a, "ra");
}

void	pa_rra_sa_rra_sa_rra_rra(int *stack_a, int *stack_b, size_t *len_a,
	size_t *len_b)
{
	push_a(stack_a, stack_b, len_a, len_b);
	reverse_rotate(stack_a, *len_a, "rra");
	swap(stack_a, *len_a, "sa");
	reverse_rotate(stack_a, *len_a, "rra");
	swap(stack_a, *len_a, "sa");
	reverse_rotate(stack_a, *len_a, "rra");
	reverse_rotate(stack_a, *len_a, "rra");
}
