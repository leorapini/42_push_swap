/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:29:34 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/24 13:42:01 by lpinheir         ###   ########.fr       */
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

	i = 0;
	while (i < len)
	{
		printf("%d\n", array[i]);
		i++;
	}
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
		number = (long int) ft_atoi(argv[j]);
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
