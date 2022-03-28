/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:03:45 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/28 11:32:23 by lpinheir         ###   ########.fr       */
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
		printf("%s\n", operation);
	}
}
