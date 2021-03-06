/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:41:15 by lpinheir          #+#    #+#             */
/*   Updated: 2022/03/24 13:53:07 by lpinheir         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == '-' && i == 0)
			;
		else if ((ft_isdigit(s[i])) == 0)
			return (0);
		i++;
	}
	return (1);
}
