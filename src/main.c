/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:46:24 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/28 15:38:17 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stk)
{
	ft_printf("+---------------+\n");
	ft_printf("|     Stack     |\n");
	ft_printf("+---------------+\n");
	printf("|   Size: %3d   |\n", ft_stack_size(stk));
	ft_printf("+---------------+\n");
	ft_printf("| Index | Value |\n");
	ft_printf("+---------------+\n");
	while (stk)
	{
		printf("| %5d | %5d |\n", stk->index, stk->content);
		stk = stk->next;
	}
	ft_printf("+---------------+\n");
}

static int	ft_sort(int ar, char *av[], t_stack **stk_a, t_stack **stk_b)
{
	if (ar < 2)
		ft_error("Error");
	if (!ft_check_args(ar, av, stk_a))
		ft_error("Error");
	add_index(stk_a);
	if (ft_stack_size(*stk_a) == 2)
		return (sort_2(stk_a));
	else if (ft_stack_size(*stk_a) == 3)
		return (sort_3(stk_a, stk_b));
	else if (ft_stack_size(*stk_a) == 4)
		return (sort_4(stk_a, stk_b));
	else if (ft_stack_size(*stk_a) == 5)
		return (sort_5(stk_a, stk_b));
	else if (ft_stack_size(*stk_a) > 5)
		return (radix_sort(stk_a, stk_b, ft_stack_size(*stk_a)));
	return (1);
}

int	main(int ar, char *av[])
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_stack	*tmp;
	int		ops;

	stk_a = NULL;
	stk_b = NULL;
	ops = 0;
	while (stk_a)
	{
		stk_a->lis_length = 1;
		stk_a = stk_a->next;
	}
	ops += ft_sort(ar, av, &stk_a, &stk_b);
	tmp = stk_a;
	printf("\nOperations: %d\n\n", ops);
	print_stack(tmp);
	ft_stack_clear(&stk_a);
	ft_stack_clear(&stk_b);
	return (0);
}
