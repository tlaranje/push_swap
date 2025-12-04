/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:17:10 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 23:33:30 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	move_chunks(t_stack **stk_a, t_stack **stk_b, int start, int end)
{
	int	ops;
	int	index;
	int	median;

	ops = 0;
	median = (start + end) / 2;
	while (1)
	{
		index = find_target_index(*stk_a, start, end);
		if (index == -1)
			break ;
		ops += rotate_to_top(stk_a, index, ra, rra);
		if ((*stk_a)->index < median)
			ops += pb(stk_a, stk_b) + rb(stk_b);
		else
			ops += pb(stk_a, stk_b);
	}
	return (ops);
}

static int	move_back(t_stack **stk_a, t_stack **stk_b)
{
	int	ops;
	int	index;

	ops = 0;
	while (*stk_b)
	{
		index = find_max_index(*stk_b);
		ops += rotate_to_top(stk_b, index, rb, rrb);
		ops += pa(stk_a, stk_b);
	}
	return (ops);
}

int	chunks_sort(t_stack **stk_a, t_stack **stk_b, int c_size, int s_size)
{
	int	ops;
	int	start;
	int	end;

	ops = 0;
	start = 0;
	while (start < s_size)
	{
		end = start + c_size - 1;
		if (end >= s_size)
			end = s_size - 1;
		ops += move_chunks(stk_a, stk_b, start, end);
		start += c_size;
	}
	ops += move_back(stk_a, stk_b);
	return (ops);
}
