/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:18:35 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/25 16:34:18 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_bit(t_stack *stk_a)
{
	int max;
	int bits;

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

static void	add_index(t_stack **stk_a)
{
	t_stack	*n1;
	t_stack	*n2;
	int		i;

	i = 0;
	n1 = *stk_a;
	while (n1)
	{
		i = 0;
		n2 = *stk_a;
		while (n2)
		{
			if (n1->content > n2->content)
				i++;
			n2 = n2->next;
		}
		n1->index = i;
		n1 = n1->next;
	}
}

int radix_sort(t_stack **stk_a, t_stack **stk_b, int stk_size)
{
	int	max_bits;
	int	ops;
	int	i;
	int	j;

	ops = 0;
	i = 0;
	j = 0;
	add_index(stk_a);
	max_bits = find_max_bit(*stk_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < stk_size)
		{
			if (((*stk_a)->index >> i) & 1)
				ops += ra(stk_a);
			else
				ops += pb(stk_a, stk_b);
			j++;
		}
		while (ft_stack_size(*stk_b) != 0)
			ops += pa(stk_a, stk_b);
		i++;
	}
	return (ops);
}
