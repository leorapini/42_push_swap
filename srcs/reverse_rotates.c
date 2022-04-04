/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:21:50 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/04 11:49:41 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(int *stack, size_t current_len, char *operation)
{
	size_t	i;
	int		new_first;

	i = current_len - 1;
	if (current_len > 0)
	{
		new_first = stack[current_len - 1];
		while (i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
		stack[i] = new_first;
		if (operation != NULL)
			printf("%s\n", operation);
	}
}

void	rev_rotate_a_rev_rotate_b(int *stack_a, int *stack_b, size_t len_a,
	size_t len_b)
{
	if (len_a > 0 || len_b > 0)
	{
		reverse_rotate(stack_a, len_a, NULL);
		reverse_rotate(stack_b, len_b, NULL);
		printf("rrr\n");
	}
}
