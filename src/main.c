/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:46:24 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/18 16:37:33 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ar, char *av[])
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_list *tmp;
	int		i;

	lst_a = NULL;
	lst_b = NULL;
	if (ar < 2)
		ft_error("Error\n");
	if (!check_nbr_args(ar, av, &lst_a))
		ft_error("Error\n");
	i = 0;
	tmp = lst_a;
	printf("Before any instructions\nlst_a:\n");
	while (tmp)
	{
		printf("    %d: %d\n", i, *(int *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	tmp = lst_a;
	i = 0;
	sa(lst_a);
	printf("\nAfter any instructions\nlst_a:\n");
	while (tmp)
	{
		printf("    %d: %d\n", i, *(int *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
