/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:21:34 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/24 14:21:33 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_it(int *stack_a, int *stack_b, size_t len_a, size_t len_b)
{
	if (len_b > 50)
		printf("%d", stack_b[0]);
	swap_a(stack_a, len_a);
}

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
	printf("PRE SORT\n");
	print_array(stack_a, len_a);
	swap_it(stack_a, stack_b, len_a, len_b);
	printf("\nPOST SORT\n");
	print_array(stack_a, len_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
