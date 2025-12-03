/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:46:24 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 17:18:50 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stk, char *nome)
{
	ft_printf("\n+----------------------------------+\n");
	ft_printf("|              Stack %s             |\n", nome);
	ft_printf("+----------------------------------+\n");
	printf("|             Size: %-3d            |\n", ft_stack_size(stk));
	ft_printf("+----------------------------------+\n");
	ft_printf("| Index | Lis_len | Is_lis | Value |\n");
	ft_printf("+----------------------------------+\n");
	while (stk)
	{
		printf("| %5d | %7d | %6d | %5d |\n",
			stk->index, stk->lis_length, stk->is_lis, stk->content);
		stk = stk->next;
	}
	ft_printf("+----------------------------------+\n");
}

/* void	sort_stack(t_stack **stk_a, t_stack **stk_b, int *ops)
{

} */

static void	ft_sort(t_stack **stk_a, t_stack **stk_b, int *ops)
{
	int	stk_size;

	stk_size = ft_stack_size(*stk_a);

	if (stk_size == 2)
		*ops += sort_2(stk_a);
	else if (stk_size == 3)
		*ops += sort_3(stk_a, stk_b);
	else if (stk_size == 4)
		*ops += sort_4(stk_a, stk_b);
	else if (stk_size == 5)
		*ops += sort_5(stk_a, stk_b);
	else if (stk_size > 5)
		sort_stack(stk_a, stk_b, ops);
}

int	main(int ar, char *av[])
{
	t_stack		*stk_a;
	t_stack		*stk_b;
	static int	ops;

	ops = 0;
	stk_a = NULL;
	stk_b = NULL;
	if (ar < 2)
		ft_error("Error");
	if (!check_args(ar, av, &stk_a))
		ft_error("Error");
	add_index(&stk_a);
	move_lis(&stk_a, &stk_b, ft_stack_size(stk_a), &ops);
	ft_sort(&stk_a, &stk_b, &ops);
	print_stack(stk_a, "A");
	print_stack(stk_b, "B");
	printf("\nOperations: %d\n\n", ops);
	ft_stack_clear(&stk_a);
	ft_stack_clear(&stk_b);
	return (0);
}
