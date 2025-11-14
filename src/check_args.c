/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:15 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/14 14:01:35 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	check_multi_args(char *av[])
{

	return (0);
}

static int	check_single_arg(char *av[])
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (!(ft_isdigit(av[1][i])))
			return (-1);
		i++;
	}
	return (0);
}

int	check_args(int ar, char *av[])
{
	if (ar == 2)
		check_single_arg(av[1]);



	return (0);
}