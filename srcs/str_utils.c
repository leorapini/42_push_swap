/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:41:15 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/24 13:47:41 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_argv_num(char **argv)
{
	int	i;

	i = START_ARGV;
	while (argv[i] != NULL)
	{
		if (!(str_is_digit(argv[i])))
			return (0);
		i++;
	}
	return (1);
}

int	str_is_digit(char *s)
{
	int negative_control;

	negative_control = 0;
	while (*s)
	{
		if (*s == '-' && negative_control == 0)
			negative_control = 1;
		else if ((ft_isdigit(*s)) == 0)
			return (0);
		s++;
	}
	return (1);
}
