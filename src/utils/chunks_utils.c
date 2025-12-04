/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:09:18 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/03 23:33:18 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *stk_b)
{
	int	max_index;
	int	best_index;
	int	current_index;

	best_index = 0;
	current_index = 0;
	max_index = -1;
	while (stk_b)
	{
		if (stk_b->index > max_index)
		{
			max_index = stk_b->index;
			best_index = current_index;
		}
		current_index++;
		stk_b = stk_b->next;
	}
	return (best_index);
}

int	rotate_to_top(t_stack **stk, int index,
		int (*r)(t_stack **), int (*rr)(t_stack **))
{
	int	ops;
	int	size;
	int	moves;

	ops = 0;
	size = ft_stack_size(*stk);
	if (index <= size / 2)
	{
		moves = index;
		while (moves--)
			ops += r(stk);
	}
	else
	{
		moves = size - index;
		while (moves--)
			ops += rr(stk);
	}
	return (ops);
}

int	find_target_index(t_stack *stk_a, int start, int end)
{
	int	index;

	index = 0;
	while (stk_a)
	{
		if (stk_a->index >= start && stk_a->index <= end)
			return (index);
		index++;
		stk_a = stk_a->next;
	}
	return (-1);
}
