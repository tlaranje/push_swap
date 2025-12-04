/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:46:24 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 23:26:13 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stk, char *nome)
{
	ft_printf("\n+---------------+\n");
	ft_printf("|    Stack %s    |\n", nome);
	ft_printf("+---------------+\n");
	printf("|   Size: %-3d   |\n", ft_stack_size(stk));
	ft_printf("+---------------+\n");
	ft_printf("| Index | Value |\n");
	ft_printf("+---------------+\n");
	while (stk)
	{
		printf("| %5d | %5d |\n", stk->index, stk->content);
		stk = stk->next;
	}
	ft_printf("+---------------+\n\n");
}

static int	ft_sort(int ar, char *av[], t_stack **stk_a, t_stack **stk_b)
{
	int	stk_size;

	if (ar < 2)
		ft_error("Error");
	if (!ft_check_args(ar, av, stk_a))
		ft_error("Error");
	add_index(stk_a);
	stk_size = ft_stack_size(*stk_a);
	if (ft_stack_size(*stk_a) == 2)
		return (sort_2(stk_a));
	else if (ft_stack_size(*stk_a) == 3)
		return (sort_3(stk_a));
	else if (ft_stack_size(*stk_a) == 4)
		return (sort_4(stk_a, stk_b));
	else if (ft_stack_size(*stk_a) == 5)
		return (sort_5(stk_a, stk_b));
	else if (ft_stack_size(*stk_a) > 5)
		return (chunks_sort(stk_a, stk_b, get_chunk_size(stk_size), stk_size));
	return (1);
}

int	main(int ar, char *av[])
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	int		ops;

	stk_a = NULL;
	stk_b = NULL;
	ops = 0;
	ops += ft_sort(ar, av, &stk_a, &stk_b);
	ft_stack_clear(&stk_a);
	ft_stack_clear(&stk_b);
	return (0);
}
