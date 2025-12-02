/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:58:42 by tlaranje          #+#    #+#             */
/*   Updated: 2025/12/02 14:57:34 by tlaranje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lis(t_stack **stk_a)
{
	t_stack	*cur;
	t_stack	*prev;
	int		max_lis;

	max_lis = 0;
	cur = *stk_a;
	while (cur)
	{
		prev = *stk_a;
		cur->lis_length = 1;
		while (prev != cur)
		{
			if (prev->content < cur->content
				&& prev->lis_length + 1 > cur->lis_length)
				cur->lis_length = prev->lis_length + 1;
			prev = prev->next;
		}
		if (cur->lis_length > max_lis)
			max_lis = cur->lis_length;
		cur = cur->next;
	}
	return (max_lis);
}

void	set_is_lis(t_stack **stk_a, int max_len)
{
	t_stack	*cur;
	t_stack *tmp;
	t_stack *res;

	cur = NULL;
	while (max_len > 0)
	{
		tmp = *stk_a;
		res = NULL;
		while (tmp)
		{
			 if (tmp->lis_length == max_len
				&& (!cur || tmp->content <= cur->content))
				if (!res)
					res = tmp;
			tmp = tmp->next;
		}
		if (!res) break;
		res->is_lis = 1;
		cur = res;
		max_len--;
	}
}

int	move_stk(t_stack **stk_a, t_stack **stk_b, int stk_size)
{
	int	ops;

	ops = 0;
	while (stk_size--)
	{
		if ((*stk_a)->is_lis == 1)
			ops += ra(stk_a);
		else
			ops += pb(stk_a, stk_b);
	}
	return (ops);
}
