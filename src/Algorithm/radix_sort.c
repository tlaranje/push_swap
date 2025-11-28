/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:18:35 by tlaranje          #+#    #+#             */
/*   Updated: 2025/11/28 15:39:04 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_lis(t_stack *stk_a)
{
	t_stack	*current;
	t_stack	*prev;
	int		max_lis;

	max_lis = 0;
	current = stk_a;
	while (current)
	{
		prev = stk_a;
		while (prev != current)
		{
			if (prev->content < current->content)
			{
				if (prev->lis_length + 1 > current->lis_length)
					current->lis_length = prev->lis_length + 1;
			}
			prev = prev->next;
		}
		current = current->next;
	}
	current = stk_a;
	while (current)
	{
		if (current->lis_length > max_lis)
			max_lis = current->lis_length;
		current = current->next;
	}
	return (max_lis);
}

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
	printf("\n\nMax lis: %d\n\n", find_max_lis(*stk_a));
	while (i < find_max_bit(*stk_a))
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
		while (*stk_b)
			ops += pa(stk_a, stk_b);
		i++;
	}
	return (ops);
}
