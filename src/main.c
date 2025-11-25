/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:46:24 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/25 16:56:33 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort(int ar, char *av[], t_stack **stk_a, t_stack **stk_b)
{
	if (ar < 2)
		ft_error("Error");
	if (!ft_check_args(ar, av, stk_a))
		ft_error("Error");
	if (ft_stack_size(*stk_a) == 2)
		return (sort_2(stk_a));
	else if (ft_stack_size(*stk_a) == 3)
		return (sort_3(stk_a, stk_b));
	else if (ft_stack_size(*stk_a) == 4)
		return (sort_4(stk_a, stk_b));
	else if (ft_stack_size(*stk_a) == 5)
		return (sort_5(stk_a, stk_b));
	else if (ft_stack_size(*stk_a) > 5)
		return(radix_sort(stk_a, stk_b, ft_stack_size(*stk_a)));
	return (1);
}

int	main(int ar, char *av[])
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_stack *tmp;
	int		ops;

	stk_a = NULL;
	stk_b = NULL;
	ops = 0;
	ops += ft_sort(ar, av, &stk_a, &stk_b);
	tmp = stk_a;
	printf("\nOperations: %d\n\n", ops);
	printf("stack_a: Size: %d\n", ft_stack_size(stk_a));
	while (tmp)
	{
		ft_printf("    %d: %d\n", tmp->index, tmp->content);
		tmp = tmp->next;
	}
	ft_stack_clear(&stk_a);
	ft_stack_clear(&stk_b);
	return (0);
}
