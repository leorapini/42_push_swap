/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:21:34 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/24 11:37:30 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*stack_a;
	size_t	len;
	size_t	i;
	size_t	j;

	i = START_ARGV;
	j = 0;
	len = argc - 1;
	if (argc <= 2)
		exit(1);
	if (argv[1] == NULL || !(is_argv_num(argv)))
		ft_error(1);
	stack_a = (int *) malloc(len * sizeof(int));
	if (stack_a == NULL)
		ft_error(1);
	copy_to_stack_a(argv, stack_a, len);
	print_array(stack_a, len);
	free(stack_a);
	return (0);
}
