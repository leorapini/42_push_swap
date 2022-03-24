/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:21:34 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/24 14:44:59 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	size_t	len_a;
	size_t	len_b;
	size_t	i;
	size_t	j;

	i = START_ARGV;
	j = 0;
	len_a = argc - 1;
	len_b = 0;
	if (argc <= 2)
		exit(1);
	if (argv[1] == NULL || !(is_argv_num(argv)))
		ft_error(1);
	stack_a = (int *) malloc(len_a * sizeof(int));
	stack_b = (int *) malloc(len_b * sizeof(int));
	if (stack_a == NULL || stack_b == NULL)
		ft_error(1);
	copy_to_stack_a(argv, stack_a, len_a);
	swap_it(stack_a, stack_b, len_a, len_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
