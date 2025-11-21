/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:46:24 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/21 16:34:12 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort(t_stack *stk_a, t_stack *stk_b)
{
	(void)stk_b;
	if (ft_is_sort(stk_a))
		return (0);
	return (1);
}

int	main(int ar, char *av[])
{
	t_stack	*stk_a;
	t_stack	*stk_b = NULL;
	t_stack	*tmp_a;
	int		i;

	stk_a = NULL;
	if (ar < 2)
		ft_error("Error\n");
	if (!ft_check_args(ar, av, &stk_a))
		ft_error("Error\n");
	if (!ft_sort(stk_a, stk_b))
		ft_error("Error\n");
	i = 0;
	tmp_a = stk_a;
	printf("stack_a: Max: %d Size: %d\n", ft_max(stk_a), ft_stack_size(stk_a));
	while (tmp_a)
	{
		printf("    %d: %d\n", i, tmp_a->content);
		tmp_a = tmp_a->next;
		i++;
	}
	ft_stack_clear(&stk_a);
	return (0);
}
