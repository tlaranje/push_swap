/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:18:35 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 23:33:56 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_bit(t_stack *stk_a)
{
	int	max;
	int	bits;

	max = 0;
	bits = 0;
	while (stk_a)
	{
		if (stk_a->index > max)
			max = stk_a->index;
		stk_a = stk_a->next;
	}
	while (max != 0)
	{
		max /= 2;
		bits++;
	}
	return (bits);
}

int	radix_sort(t_stack **stk_a, t_stack **stk_b, int stk_size)
{
	int	ops;
	int	i;
	int	j;

	ops = 0;
	i = 0;
	while (i < find_max_bit(*stk_a))
	{
		stk_size = ft_stack_size(*stk_a);
		j = 0;
		while (j < stk_size)
		{
			if (((*stk_a)->index >> i) & 1)
				ops += ra(stk_a);
			else
				ops += pb(stk_a, stk_b);
			j++;
		}
		while (*stk_b)
			ops += pa(stk_a, stk_b);
		i++;
	}
	return (ops);
}
