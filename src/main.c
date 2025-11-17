/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:46:24 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/17 17:04:17 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ar, char *av[])
{
	arrays	*lst;
	int		i;

	lst = NULL;
	i = 0;
	if (ar < 2)
		return (-1);
	if (ar == 2)
		convert_args(ar, av, 1, &lst);
	else
		convert_args(ar, av, 0, &lst);
	while (lst->strs[i])
	{
		printf("Str %d: %s\n", i, lst->strs[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (lst->ints[i])
	{
		printf("Int %d: %d\n", i, lst->ints[i]);
		i++;
	}
	return (0);
}
