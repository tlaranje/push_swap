/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:17:10 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 10:02:20 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index(t_stack *stk, int start, int end, int mode)
{
	int	i;
	int	best;
	int	val;

	i = 0;
	best = -1;
	val = (mode) ? -1 : 2147483647;
	while (stk)
	{
		if (mode && stk->index > val)
		{
			val = stk->index;
			best = i;
		}
		else if (!mode && stk->index >= start && stk->index <= end)
			return (i);
		i++;
		stk = stk->next;
	}
	return (best);
}

static int	rotate_to_top(t_stack **stk, int index,
	int (*r)(t_stack **), int (*rr)(t_stack **))
{
	int	ops;
	int	size;

	ops = 0;
	size = ft_stack_size(*stk);
	while (index >= 0 && index < size && index != 0)
	{
		if (index <= size / 2)
		{
			ops += r(stk);
			index--;
		}
		else
		{
			ops += rr(stk);
			index = (index + 1 == size) ? 0 : index + 1;
		}
	}
	return (ops);
}

static int	move(t_stack **a, t_stack **b, int start, int end, int back)
{
	int	ops;
	int	idx;
	int	med;

	ops = 0;
	med = (start + end) / 2;
	while (!back && (idx = find_index(*a, start, end, 0)) != -1)
	{
		ops += rotate_to_top(a, idx, ra, rra);
		ops += pb(a, b);
		if ((*b)->index < med)
			ops += rb(b);
	}
	while (back && *b)
	{
		idx = find_index(*b, 0, 0, 1);
		ops += rotate_to_top(b, idx, rb, rrb);
		ops += pa(a, b);
	}
	return (ops);
}

int	chunks_sort(t_stack **a, t_stack **b, int c_size, int s_size)
{
	int	ops;
	int	start;
	int	end;

	ops = 0;
	start = 0;
	while (start < s_size)
	{
		end = (start + c_size - 1 >= s_size) ? s_size - 1 : start + c_size - 1;
		ops += move(a, b, start, end, 0);
		start += c_size;
	}
	ops += move(a, b, 0, 0, 1);
	return (ops);
}
