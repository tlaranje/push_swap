/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:15 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/17 17:10:58 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	convert_args(int ar, char *av[], int is_single, arrays **lst)
{
	int	i = 0;
	int	count = 0;

	*lst = malloc(sizeof(arrays));
	(*lst)->next = NULL;
	if (is_single)
		(*lst)->strs = ft_split(av[1], ' ');
	else
	{
		(*lst)->strs = malloc(sizeof(char *) * ar);
		while (i < ar - 1)
		{
			(*lst)->strs[i] = av[i + 1];
			i++;
		}
		(*lst)->strs[i] = NULL;
	}
	while ((*lst)->strs[count])
		count++;
	(*lst)->ints = malloc(sizeof(int) * count);
	i = 0;
	while (i < count)
	{
		(*lst)->ints[i] = ft_atoi((*lst)->strs[i]);
		i++;
	}
}

static int	check_args(char *av[], int is_single)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if ((!(ft_isdigit(av[j][i])) && !ft_issign(av[j][i])
			&& !ft_isspace(av[j][i])))
				return (0);
			i++;
		}
		if (!is_single)
			j++;
		else
			break ;
	}
	return (1);
}

int	check_nbr_args(int ar, char *av[])
{
	if (ar == 2)
		return(check_args(av, 1));
	else
		return(check_args(av, 0));
	return (0);
}
