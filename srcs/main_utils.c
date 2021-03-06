/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:29:34 by lpinheir          #+#    #+#             */
/*   Updated: 2022/04/28 08:33:06 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int exit_code)
{
	printf("Error\n");
	exit(exit_code);
}

void	print_array(int *array, size_t len)
{
	size_t	i;

	if (len == 0)
	{
		printf("EMPTY\n");
		return ;
	}
	i = 0;
	printf("[");
	while (i < len)
	{
		printf("%d,", array[i]);
		i++;
	}
	printf("]\n");
}

void	copy_to_stack_a(char **argv, int *stack_a, size_t len)
{
	size_t		i;
	size_t		j;
	long int	number;

	i = 0;
	j = START_ARGV;
	number = 0;
	while (i < len)
	{
		number = (long int)ft_atoi(argv[j]);
		if (is_number_repeated(stack_a, number, i))
			ft_error(1);
		stack_a[i] = number;
		i++;
		j++;
	}
}

int	is_number_repeated(int *stack_a, long int number, size_t current_len)
{
	size_t	i;

	i = 0;
	if (current_len == 0)
		return (0);
	while (i < current_len)
	{
		if (number == stack_a[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_a_stack_sorted(int *stack_a, size_t current_len)
{
	size_t	i;

	i = 0;
	while (i < current_len)
	{
		if (i + 1 < current_len)
			if (stack_a[i] > stack_a[i + 1])
				return (0);
		i++;
	}
	return (1);
}
