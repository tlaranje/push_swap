/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:46:24 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/24 16:09:14 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort(t_stack **stk_a, t_stack **stk_b)
{
	if (ft_is_sort(*stk_a))
		ft_error("Error\n");
	if (ft_stack_size(*stk_a) == 2)
		return (sort_2(stk_a));
	else if (ft_stack_size(*stk_a) == 3)
		return (sort_3(stk_a, stk_b));
	else if (ft_stack_size(*stk_a) == 4)
		return (sort_4(stk_a, stk_b));
	else if (ft_stack_size(*stk_a) == 5)
		return (sort_5(stk_a, stk_b));
	else if (ft_stack_size(*stk_a) > 5)
		return (merge_sort(stk_a, 0, ft_stack_size(*stk_a) - 1));
	return (1);
}

int	main(int ar, char *av[])
{
	int		i;
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_stack	*tmp_a;

	stk_a = NULL;
	ft_putstr_fd("\n", 1);
	if (ar < 2)
		ft_error("Error\n");
	if (!ft_check_args(ar, av, &stk_a))
		ft_error("Error\n");
	printf("\n\nOperations: %d\n", ft_sort(&stk_a, &stk_b));
	i = 0;
	tmp_a = stk_a;
	ft_putstr_fd("\n", 1);
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
