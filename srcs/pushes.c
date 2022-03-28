/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:30:28 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/28 10:53:05 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	insert_item_at_top(int *stack, int item, size_t len)
{
	size_t	i;

	i = len + 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = item;
}

static void	remove_item_at_top(int *stack, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

void	push_b(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	if (*len_a > 0)
	{
		insert_item_at_top(stack_b, stack_a[0], *len_b);
		remove_item_at_top(stack_a, *len_a);
		*len_a = *len_a - 1;
		*len_b = *len_b + 1;
		printf("pa\n");
	}
}

void	push_a(int *stack_a, int *stack_b, size_t *len_a, size_t *len_b)
{
	if (*len_b > 0)
	{
		insert_item_at_top(stack_a, stack_b[0], *len_a);
		remove_item_at_top(stack_b, *len_b);
		*len_b = *len_b - 1;
		*len_a = *len_a + 1;
		printf("pa\n");
	}
}
