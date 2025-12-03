/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:18:35 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 11:19:52 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	move_min_to_top(t_stack **stk_a)
{
	t_stack	*tmp;
	int		target;
	int		size;
	int		ops;
	int		pos;

	ops = 0;
	size = ft_stack_size(*stk_a);
	target = ft_min_index(*stk_a);
	pos = 0;
	tmp = *stk_a;
	while (tmp)
	{
		if (tmp->index == target)
			break ;
		tmp = tmp->next;
		pos++;
	}
	if (pos <= size / 2)
		while (pos--)
			ops += ra(stk_a);
	else
		while (pos++ < size)
			ops += rra(stk_a);
	return (ops);
}

int	sort_2(t_stack **stk_a)
{
	int	ops;

	ops = 0;
	if ((*stk_a)->content > (*stk_a)->next->content)
		ops += sa(stk_a);
	return (ops);
}

int	sort_3(t_stack **stk_a, t_stack **stk_b)
{
	int	ops;

	ops = 0;
	ops += move_min_to_top(stk_a);
	ops += pb(stk_a, stk_b);
	ops += sort_2(stk_a);
	ops += pa(stk_a, stk_b);
	return (ops);
}

int	sort_4(t_stack **stk_a, t_stack **stk_b)
{
	int	ops;

	ops = 0;
	ops += move_min_to_top(stk_a);
	ops += pb(stk_a, stk_b);
	ops += sort_3(stk_a, stk_b);
	ops += pa(stk_a, stk_b);
	return (ops);
}

int	sort_5(t_stack **stk_a, t_stack **stk_b)
{
	int	ops;

	ops = 0;
	ops += move_min_to_top(stk_a);
	ops += pb(stk_a, stk_b);
	ops += sort_4(stk_a, stk_b);
	ops += pa(stk_a, stk_b);
	return (ops);
}
