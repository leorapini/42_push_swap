/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:03:45 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/28 11:42:12 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *stack, size_t current_len, char *operation)
{
	size_t	i;
	int new_last;

	i = 0;
	if (current_len > 0)
	{
		new_last = stack[0];
		while (i < current_len - 1)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[i] = new_last;
		if (operation != NULL)
			printf("%s\n", operation);
	}
}

void	rotate_a_rotate_b(int *stack_a, int *stack_b, size_t len_a, size_t len_b)
{
	if (len_a > 0 || len_b > 0)
	{
		rotate(stack_a, len_a, NULL);
		rotate(stack_b, len_b, NULL);
		printf("rr\n");
	}
}
